#include "CddRTC.h"
#include "stdbool.h"

static uint8_t CddRTC_ExitInitMode (void);
static uint8_t CddRTC_EnterInitMode(void);
static void    CddRTC_SetDate(uint8_t Year, uint8_t Month, uint8_t Date, uint8_t WeekDay);
static void    CddRTC_SetTime(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint8_t Am_Pm);
static void    CddRTC_SetAlarm(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint8_t Am_Pm);
static void    CddRTC_AlarmCallBack(void);
       void    RTC_Alarm_IRQHandler(void);

// Convert decimal to BCD macro
#define DEC2BCD(x)  ((((x) / 10U) << 4U) | ((x) % 10U))
#define BCD2DEC(x)  ((((x) >> 4U) * 10U) + ((x) & 0x0FU))

#define  NVIC_RTC_ALARM_IRQ   41U

volatile uint8_t CddRTC_AlarmOccured;


void CddRTC_CalendarInit(void)
{
  /* Enable clock to PWR */
  RCC_APB1ENR |= (uint32_t)(1U << 28U);

  /* Enable backup access to config RTC      */
  PWR_CR |= (uint32_t)(1UL << 8U);
  //PWR_CR &= (uint32_t)(~(1UL << 8U));

  /* Force Backup domaine reset              */
  RCC_BDCR |= (uint32_t)(1UL << 16U);

  /* Release Backup domain reset             */
  RCC_BDCR &= (uint32_t)(~(1UL << 16U));

  /* RTC clock source selection -> HSE       */
  RCC_BDCR |= (uint32_t)(3UL << 8U);

  /* RTC clock enable                        */
  RCC_BDCR |= (uint32_t)(1UL << 15U);

  /* Disable the RTC regs write protection          */
  /* See Ch. 22.3.5 in Reference manual for details */
  RTC_WPR = 0xCAU;
  RTC_WPR = 0x53U;

  /* Enter the Initialization mode           */
  while(CddRTC_EnterInitMode()) { };

  /*              Set desired date                 */
  /* Set Date to 2025-07-15, Tuesday (weekday = 2) */
  CddRTC_SetDate(25U, 7U, 15U, 2U);

  /*                 Set desired time                    */
  /* Set Time to 09:45:30 AM in 24-hour mode (am_pm = 0) */
  CddRTC_SetTime(20U, 46U, 0U, 0U);

  /* Set hour format: Not needed because of 24-hour mode */
  // RTC_CR |= (uint32_t)(1UL << 6U);

  /* Set Asnych prescaler : PREDIV_A         */
  RTC_PRER |= (uint32_t)(0x7FUL << 16U);

  /* Set Sync prescaler   : PREDIV_S         */
  RTC_PRER |= (uint32_t)(0xFEUL << 0U);

  /* Exit the initialization mode            */
  while(!CddRTC_ExitInitMode()) { }

  /* Enable the RTC regs write protection    */
  RTC_WPR = (uint8_t)0xFFUL;
}

static uint8_t CddRTC_EnterInitMode(void)
{
  /* Set Initialization mode   */
  RTC_ISR |= (1U << 7UL);

  /* Check Initialization flag */
  return ((RTC_ISR & (1UL << 6U)) == 0U);
}


static uint8_t CddRTC_ExitInitMode(void)
{
  /* Set Free running mode     */
  RTC_ISR &= (uint32_t)(~(1U << 7UL));

  /* Check synchronization flag */
  return ((RTC_ISR & (1U << 5UL)) == (1U << 5UL));
}


static void CddRTC_SetTime(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint8_t Am_Pm)
{
  /* Set RTC time register */
  RTC_TR = (((Am_Pm            & 0x01U) << 22U) |
            ((DEC2BCD(Hours)   & 0x3FU) << 16U) |
            ((DEC2BCD(Minutes) & 0x7FU) <<  8U) |
            ((DEC2BCD(Seconds) & 0x7FU) <<  0U));
}

static void CddRTC_SetDate(uint8_t Year, uint8_t Month, uint8_t Date, uint8_t WeekDay)
{
  /* Set RTC date register */
  RTC_DR = (((DEC2BCD(Year)  & 0xFFU) << 16U) |
            ((WeekDay        & 0x07U) << 13U) |
            ((DEC2BCD(Month) & 0x1FU) <<  8U) |
            ((DEC2BCD(Date)  & 0x3FU) <<  0U));
}


void CddRTC_ReadTime(uint8_t* Hours, uint8_t* Minutes, uint8_t* Seconds, uint8_t* Am_Pm)
{
  uint32_t TimerReg = RTC_TR;

  *Hours   = (uint8_t)BCD2DEC((TimerReg >> 16U) & 0x3FU);
  *Minutes = (uint8_t)BCD2DEC((TimerReg >>  8U) & 0x7FU);
  *Seconds = (uint8_t)BCD2DEC((TimerReg >>  0U) & 0x7FU);

  *Am_Pm   = (uint8_t)(TimerReg & (1UL << 12U)) ? 1U : 0U;
}

void CddRTC_ReadDate(uint8_t* Year, uint8_t* Month, uint8_t* Date, uint8_t* WeekDay)
{
  uint32_t DateReg = RTC_DR;

  *Year    = (uint8_t)BCD2DEC((DateReg >> 16U) & 0xFFU);
  *Month   = (uint8_t)BCD2DEC((DateReg >>  8U) & 0x1FU);
  *Date    = (uint8_t)BCD2DEC((DateReg >>  0U) & 0x3FU);
  *WeekDay = (uint8_t)(       (DateReg >> 13U) & 0x07U);
}

static void CddRTC_SetAlarm(uint8_t Hours, uint8_t Minutes, uint8_t Seconds, uint8_t Am_Pm)
{
  // Set PM bit if am_pm == 1, clear if am_pm == 0
  uint32_t pm_bit = (Am_Pm ? (1UL << 22) : 0UL);

  /* Set Alarm A time */
  /* MSK3 = 0 (Hours match)     */
  /* MSK2 = 0 (Minutes match)   */
  /* MSK1 = 0 (Seconds match)   */
  RTC_ALRMAR &= (uint32_t)(~((1UL << 23U) | (1UL << 15U) | (1UL << 7U)));

  RTC_ALRMAR |= ((1UL << 31U)                        |  /* MSK4 = 1 (Date don’t care) */
                pm_bit                               |  /* AM-PM bit                  */
                ((uint32_t)DEC2BCD(Hours)   << 16U)  |
                ((uint32_t)DEC2BCD(Minutes) <<  8U)  |
                ((uint32_t)DEC2BCD(Seconds) <<  0U));
}


void CddRTC_AlarmInit(void)
{
  /* Enable clock to PWR */
  RCC_APB1ENR |= (uint32_t)(1U << 28U);

  /* Enable backup access to config RTC      */
  PWR_CR |= (uint32_t)(1UL << 8U);
  //PWR_CR &= (uint32_t)(~(1UL << 8U));

  /* Force Backup domaine reset              */
  RCC_BDCR |= (uint32_t)(1UL << 16U);

  /* Release Backup domain reset             */
  RCC_BDCR &= (uint32_t)(~(1UL << 16U));

  /* RTC clock source selection -> HSE       */
  RCC_BDCR |= (uint32_t)(3UL << 8U);

  /* RTC clock enable                        */
  RCC_BDCR |= (uint32_t)(1UL << 15U);


  /* Disable RTC registers write protection */
  /* See Ch. 22.3.5 in Reference manual for details */
  RTC_WPR = 0xCAU;
  RTC_WPR = 0x53U;

  /* Enter the initialization mode          */
  while(CddRTC_EnterInitMode()) { };

  /* Set Date to 2025-07-15, Tuesday (weekday = 2) */
  CddRTC_SetDate(25U, 7U, 15U, 2U);

  /* Set Time to 09:45:30 AM in 24-hour mode (am_pm = 0) */
  CddRTC_SetTime(20U, 58U, 0U, 0U);

  /* Set Alarm                              */
  CddRTC_SetAlarm(21U, 0U, 0U, 0U);

  /* Ignore Weekday                         */
  RTC_ALRMAR |=(uint32_t)((1UL << 31U));

  /* Enable Alarm                           */
  RTC_CR |=(uint32_t)((1UL << 8U));

  /* Clear Alarm A Flag                     */
  RTC_ISR &= (uint32_t)(~(1UL << 8U));

  /* Enable Alarm A Interrupt               */
  RTC_CR |=(uint32_t)((1UL << 12U));

  /* Configure RTC Alarm interrupt                    */
  /* EXTI Line 17 is connected to the RTC Alarm event */
  EXTI_IMR  |= (uint32_t)(1UL << 17U);
  /* Rising trigger selection */
  EXTI_RTSR |= (uint32_t)(1UL << 17U);

  /* Enable Alarm Interrupt in NVIC         */
  NVIC_ISER1 |= (1UL << (NVIC_RTC_ALARM_IRQ - 32U));

  /* Exit the initialization mode            */
  while(!CddRTC_ExitInitMode()) { }

  /* Enable the RTC regs write protection    */
  RTC_WPR = (uint8_t)0xFFUL;

}

static void CddRTC_AlarmCallBack(void)
{
  /* Do the following or Blink a LED */
  CddRTC_AlarmOccured = 0x12;
}

void RTC_Alarm_IRQHandler(void)
{
  /* Check if Alarm A flag is set */
  if(RTC_ISR & (1UL << 8U))
  {
    /* Clear Alarm A flag */
    RTC_ISR &= ~(1UL << 8U);

    /* Alarm call back function */
    CddRTC_AlarmCallBack();
  }

  /*  Clear EXTI line 17 pending bit */
  EXTI_PR |= (1UL << 17U);
}

