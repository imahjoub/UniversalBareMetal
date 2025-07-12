#include "CddTim.h"


void CddTim_Init(void)
{
  /* Enable Clock access to TIM2                    */
  RCC_APB1ENR |= (uint32_t)(1UL << 0U);

  /* Set timer Prescaler                            */
  /* Prescale to 100kHz (45MHz / 4500)              */
  //TIM2_PSC = 45000UL - 1UL; /* for 4Hz */
  TIM2_PSC = 180UL - 1UL;

  /* Set Auto-reload value                          */
  TIM2_ARR = 500UL - 1UL;

  /* Reset the timer count                          */
  TIM2_CNT = (uint32_t)0UL;

  /* Set PA1 (ch1) and PA0 (ch2) to 100: PWM mode 1 */
  TIM2_CCMR1 &= (uint32_t)(~(1UL << 4U));
  TIM2_CCMR1 |= (uint32_t)(1UL << 5U);
  TIM2_CCMR1 |= (uint32_t)(1UL << 6U);

  TIM2_CCMR1 &= (uint32_t)(~(1UL << 12U));
  TIM2_CCMR1 |= (uint32_t)(1UL << 13U);
  TIM2_CCMR1 |= (uint32_t)(1UL << 14U);

  /* Enable preload register on CH1 and CH2         */
  TIM2_CCMR1 |= (uint32_t)((1UL << 3U) | (1UL << 11U));

  /* Enable (ch2) and (ch1)                         */
   TIM2_CCER |= (uint32_t)(1UL << 0U);
   TIM2_CCER |= (uint32_t)(1UL << 4U);

  /* Enable timer                                   */
   TIM2_CR1 |= (uint32_t)(1UL << 0U);

  /* Force update generation                        */
  TIM2_EGR |= (uint32_t)1UL;
}



void CddTim_SetPwmDutyCycle(uint8_t PwmChannel, uint32_t DutyCycle)
{
  /* Set Duty cycle */
  switch(PwmChannel)
  {
  case 1:
    TIM2_CCR1 = DutyCycle;
    break;
  case 2:
    TIM2_CCR2 = DutyCycle;
    break;
  default:
    break;
  }
}




