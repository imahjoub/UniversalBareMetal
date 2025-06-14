#include "CddTim.h"


void CddTim_Init(void)
{
  /* Enable Clock access to TIM2                    */
  RCC_APB1ENR |= (uint32_t)(1UL << 0U);

#if 0

  /* Set timer Prescaler                            */
  TIM2_PSC |= (uint32_t)1800UL - 1UL;

  /* Set Auto-reload value                          */
  TIM2_ARR |= (uint32_t)1000UL - 1UL;

  /* Reset the timer count                          */
  TIM2_CNT &=(uint32_t)(~(0xFFFF));

  /* Set PA1 (ch1) and PA0 (ch2) to 100: PWM mode 1 */
  TIM2_CCMR1 &= (uint32_t)(~(1UL << 4U));
  TIM2_CCMR1 |= (uint32_t)(1UL << 5U);
  TIM2_CCMR1 |= (uint32_t)(1UL << 6U);

  TIM2_CCMR1 &= (uint32_t)(~(1UL << 12U));
  TIM2_CCMR1 |= (uint32_t)(1UL << 13U);
  TIM2_CCMR1 |= (uint32_t)(1UL << 14U);

  /* Enable (ch2) and (ch1)                         */
   TIM2_CCER |= (uint32_t)(1UL << 0U);
   TIM2_CCER |= (uint32_t)(1UL << 4U);

  /* Enable timer                                   */
   TIM2_CR1 |= (uint32_t)(1UL << 0U);
#endif

  // Set Prescaler, Auto-reload register
  TIM2_PSC = 44999UL + 1UL;  // Prescale to 100kHz (45MHz / 4500)
  TIM2_ARR = 499UL   + 1UL;  // 100Hz PWM frequency (100kHz / 1000)

  // Configure TIM2 CCMR1
  TIM2_CCMR1 &= (uint32_t)(~(0xFFUL));                     // Clear bits for ch1 and ch2
  TIM2_CCMR1 |= (0x6 << 4) | (0x6 << 12);    // PWM mode 1 on CH1 and CH2
  TIM2_CCMR1 |= (1 << 3) | (1 << 11);        // Enable preload register on CH1 and CH2

  // Enable output for CH1 and CH2
  TIM2_CCER |= (1 << 0) | (1 << 4);  // Enable output for CH1 and CH2

  // Enable Counter
  TIM2_CR1 |= (1 << 0);

  // Force update generation
  TIM2_EGR |= 1;
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




