#ifndef GPIO_2025_06_10_H
  #define GPIO_2025_06_10_H

  #include <Mcal/Mcu.h>

  #define RCC_AHB1ENR_GPIOAEN  (1UL << 0U)
  #define RCC_AHB1ENR_GPIOCEN  (1UL << 2U)

  #define USER_LED               5UL
  #define WAKEUP_PIN             3UL
  #define USER_BUTTON           13UL

  void Led_On(void);
  void Led_Off(void);
  void Led_Blinky(void);
  void GPIO_Init(void);

#endif /* GPIO_2025_06_10_H */





