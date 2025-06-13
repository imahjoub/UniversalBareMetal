#include "CddWwdg.h"
#include "Mcal/Mcu.h"
#include "Mcal/Gpio.h"


/* Note   PCLK1 = 180Mhz/ 4  = 45Mhz */

#define RCC_CSR_WWDGRSTF     (1UL << 30U)
#define RCC_CSR_RMVF         (1UL << 24U)


void CddWwdg_Init(void)
{
  /* Enable the periherial clock WWDG */
  RCC_APB1ENR |= (uint32_t)(1UL << 11U);

  /* Set prescaler to have a roller each anout ~2s */
  WWDG_CFR |= (uint32_t)(1UL << 7U);
  WWDG_CFR |= (uint32_t)(1UL << 8U);

  /* Set windiw value to same value ~2s as downcount in order to refersg the WWDG immediadetly */
  WWDG_CFR &= (uint32_t)(~(0x7FUL << 0U));
  WWDG_CFR |= (uint32_t)(0x7FUL << 0U);

  /* Set counter */
  WWDG_CR &= (uint32_t)(~(0x7FUL << 0U));
  WWDG_CR |= (uint32_t)(0x7FUL << 0U);

  /* Enable WWDG */
  WWDG_CR |= (uint32_t)(1UL << 7U);

}

void CddWwdg_HandleReset(void)
{
  /* Check if system resumed from IWDG reset */
  if(RCC_CSR & RCC_CSR_WWDGRSTF)
  {
    /* Keep LED on until button is pressed */
    Led_On();

    /* Clear IWDG reset flag */
    RCC_CSR |= RCC_CSR_RMVF;

    /* Simple delay */
    for(volatile uint32_t i = 0U; i < (uint32_t)0x00FFFFFFUL; ++i) { }

    /* Turn Off Led */
    Led_Off();
  }

}

