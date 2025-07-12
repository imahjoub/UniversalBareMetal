#include "stdint.h"

#include <Cdd/CddAdc/CddAdc.h>
#include <Cdd/CddIWdg/CddIWdg.h>
#include <Cdd/CddWWdg/CddWWdg.h>
#include <Cdd/CddTim/CddTim.h>
#include <Mcal/Gpio.h>
#include <Mcal/Gpt.h>
#include <Mcal/Mcu.h>

#include <Util/C/UtilTimer.h>

volatile uint8_t  UserButtonIsPressed = 0U;
static   uint64_t DelayTimer;


void Adc_Task            (void);
void Blinky_Task         (void);
void EXTI15_10_IRQHandler(void);
void IWDG_Task           (void);
void WWDG_Task           (void);
void Pwm_Task            (void);
void msDelay             (uint32_t ms);


int main(void)
{
  /* Configure the System clock and flash */
  SystemInit();
  SetSysClock();

  /* Configure systick timer to generate half second delay */
  SysTick_Init();

  /*Initialize Gpio pins and EXTI */
  GPIO_Init();

  /* Initialize EXTI */
  EXTI_Init();

  /* Run a Task */
  //Blinky_Task();
  Pwm_Task();

}

/***********************************************************************/
/*                                TASKS                                */
/***********************************************************************/

/* --- Pwm Task --- */
void Pwm_Task(void)
{
  /* Initialize TIM2 */
  CddTim_Init();

  while(1)
  {
    /* Gradually increase brightness from 0 to 100% */
    for(uint32_t DutyCycle = 0U; DutyCycle < 500U; ++DutyCycle)
    {
      CddTim_SetPwmDutyCycle(1U, DutyCycle);
      CddTim_SetPwmDutyCycle(2U, (500U - DutyCycle));

      /* Add a small delay to create a visible transition */
      msDelay(30U);
    }

    for(uint32_t DutyCycle = 500U; DutyCycle > 0U; --DutyCycle)
    {
      CddTim_SetPwmDutyCycle(1U, DutyCycle);
      CddTim_SetPwmDutyCycle(2U, (500U - DutyCycle));

      /* Add a small delay to create a visible transition */
      msDelay(30U);
    }
  }
}

/* --- Blinky Task --- */
void Blinky_Task(void)
{
  DelayTimer = TimerStart(1000U);

  while(1U)
  {
    if(TimerTimeout(DelayTimer))
    {
      DelayTimer = TimerStart(1000U);
      Led_Blinky();
    }
  }
}

/* --- IWDG Task --- */
void IWDG_Task(void)
{
  /* Handle IWDG reset */
  CddIWdg_HandleReset();

  /* Initialize the IWDG */
  CddIWdg_Init();

  while(1U)
  {
    if(UserButtonIsPressed)
    {
      /* Do nothing */
      uint8_t debug_var = 0;
      (void)debug_var;
    }
    else
    {
      Led_Blinky();

      /* Refresh IWDG counter */
      IWDG_KR = IWDG_REFRESH;
    }
  }
}

/* --- WWDG Task --- */
void WWDG_Task(void)
{
  /* Handle WWDG reset */
  CddWwdg_HandleReset();

  /* Initialize the WWDG */
  CddWwdg_Init();

  while(1U)
  {
    if(UserButtonIsPressed)
    {
      /* Do nothing */
      uint8_t debug_var = 0;
      (void)debug_var;
    }
    else
    {
      Led_Blinky();

      /* Set WWDG counter */
      WWDG_CR &= (uint32_t)(~(0x7FUL << 0U));
      WWDG_CR |= (uint32_t)(0x7FUL << 0U);
    }
  }
}

/* --- ADC Task --- */
void Adc_Task(void)
{
  CddAdc_Init();

  while(1U)
  {
    volatile uint32_t Vbat_Val = CddAdc_ReadVBAT();

    (void)Vbat_Val;
  }

}

/* User button interrup handler */
void EXTI15_10_IRQHandler(void)
{
  /* Clear interrupt pending bit */
  if(EXTI_PR & (1UL << USER_BUTTON))
  {
    EXTI_PR |= (1UL << USER_BUTTON);

    /* Toggle the button pressed state */
    UserButtonIsPressed = (uint8_t)(!UserButtonIsPressed);
  }
}

/* --- Simple ms Delay --- */
void msDelay(uint32_t ms)
{
  // Simple delay loop - adjust based on your system clock
  for (uint32_t i = 0; i < ms * 1000; i++)
  {
    __asm("NOP");
  }
}

