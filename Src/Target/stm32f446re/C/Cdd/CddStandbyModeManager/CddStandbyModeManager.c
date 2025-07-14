#include "CddStandbyModeManager.h"
#include "Mcal/Gpio.h"

#define PWR_CSR_WUF    (uint32_t)(1UL << 0U)
#define PWR_CSR_SBF    (uint32_t)(1UL << 1U)

void CddSBM_StandbyWakeupPinSetup(void)
{
  /* Wait for Wakeup pin to be released                 */
  while(CddSBM_GetWakeUpStatePin() == 0U);

  /* Disable wakeup pin                                 */
  PWR_CSR &= (uint32_t)(~(1UL << 8U));

  /* Clear wakeup flags                                 */
  PWR_CR |= (uint32_t)(1UL << 2U);

  /* Enable wakeup pin                                  */
  PWR_CSR |= (uint32_t)(1UL << 8U);

  /* Enter Standby Mode                                 */
  PWR_CR |= (uint32_t)((1UL << 1U));

  /* Set SleepDeep bit in the System control register   */
  SCB_SCR |= (uint32_t)((1UL << 2U));

  /* Wait for Interrupt                                 */
  __asm volatile("wfi");

}


uint32_t CddSBM_GetWakeUpStatePin(void)
{
  return ((GPIOC_IDR & WAKEUP_PIN) == WAKEUP_PIN);
}


void CddSBM_HandleReset(void)
{
   /* Power interface clock enable PWR */
   RCC_APB1ENR |= (uint32_t)(1UL << 28U);

  /* Check and clear the Standby mode flag */
  if((PWR_CSR & PWR_CSR_SBF) == PWR_CSR_SBF)
  {
    /* Clear the StandBy Mode flag */
    PWR_CR |= (uint32_t)(1UL << 3U);

    /* Keep LED blink */
    Led_Blinky();

    /* Wait for wake up pin to be released */
    while(CddSBM_GetWakeUpStatePin() == 0U) { /* Do nothing */ }
  }

  /* Check and clear the WakeUp flag */
  if((PWR_CSR & PWR_CSR_WUF) == PWR_CSR_WUF)
  {
    /* Clear the WakeUp flag */
    PWR_CR |= (uint32_t)(1UL << 2U);
  }

}


