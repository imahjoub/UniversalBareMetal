#include "CddIWdg.h"
#include <Mcal/Gpio.h>

/* Defines */
#define IWDG_SR_PVU          0x01U  // Prescaler Value Update
#define IWDG_SR_RVU          0x02U  // Reload Value Update
#define RCC_CSR_IWDGRSTF     (1UL << 29U)
#define RCC_CSR_RMVF         (1UL << 24U)

void CddIWdg_Init(void)
{
  /* Enable write access to IWDG_PR and IWDG_RLR registers */
  IWDG_KR = 0x5555U;

  /* Set the IWDG prescaler */
  IWDG_PR = 0x00U;

  /* Set the reload value (max timeout) */
  IWDG_RLR = 0x0FFFU;

  /* Reload the IWDG counter */
  IWDG_KR = 0xAAAAU;

  /* Wait for PVU to be cleared before setting prescaler */
  //while (IWDG_SR & IWDG_SR_PVU);

  /* Wait for RVU to be cleared before setting reload value */
  //while (IWDG_SR & IWDG_SR_RVU);

  /* Start the IWDG */
  IWDG_KR = 0xCCCCU;
}

void CddIWdg_HandleReset(void)
{
  /* Check if system resumed from IWDG reset */
  if(RCC_CSR & RCC_CSR_IWDGRSTF)
  {
    /* Keep LED on until button is pressed */
    Led_On();

    /* Clear IWDG reset flag */
    RCC_CSR |= RCC_CSR_RMVF;

    /* Simple delay */
    for (volatile uint32_t i = 0U; i < (uint32_t)0x00FFFFFFUL; ++i) { }

    /* Turn Off Led */
    Led_Off();
  }
}

