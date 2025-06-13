#include "Gpio.h"

void GPIO_Init(void)
{
  /* Enable GPIOA and GPIOC clocks */
  RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN;

  /* Configure USER_LED as output (01) */
  GPIOA_MODER |=  (1UL << (USER_LED * 2U));
  GPIOA_MODER &= (uint32_t)(~(1UL << (USER_LED * 2U + 1U)));

  /* Configure USER_BUTTON as input (00) */
  GPIOC_MODER &= (uint32_t)(~((1UL << (USER_BUTTON * 2U)) | (1UL << (USER_BUTTON * 2U + 1U))));

  /* Set USER_BUTTON as pull-down (10) */
  GPIOC_PUPDR |= (1UL << (USER_BUTTON * 2U + 1U));
  GPIOC_PUPDR &= (uint32_t)(~(1UL << (USER_BUTTON * 2U)));

}

void Led_Blinky(void)
{
  /* Toggle the LED pin */
  GPIOA_ODR ^= (1UL << 5U);

  /* Simple delay */
  for (volatile uint32_t i = 0U; i < (uint32_t)0x005FFFFFUL; ++i) { }

}

void Led_On(void)
{
  /* Turn on the LED */
  GPIOA_ODR = (1UL << 5U);
}

void Led_Off(void)
{
  /* Turn off the LED */
  GPIOA_ODR &= ~(1UL << 5U);
}

