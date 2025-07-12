#ifndef CDD_TIM_2025_06_12_H
  #define CDD_TIM_2025_06_12_H

  #include <Mcal/Mcu.h>

  #define PWM_WITH_DMA

  void CddTim_Init(void);
  void CddTim_SetPwmDutyCycle(uint8_t PWMChannel, uint32_t DutyCycle);

#endif /* CDD_TIM_2025_06_12_H */

