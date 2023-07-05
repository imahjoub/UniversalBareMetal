#include <cstdint>

auto mcal_init() -> void
{
  #define RCC_AHB1ENR  (*(volatile unsigned*) 0x40023830U)
  #define GPIOA_MODER  (*(volatile unsigned*) 0x40020000U)

  RCC_AHB1ENR |= 1U;

  GPIOA_MODER |= (1U << (5U * 2U));
  GPIOA_MODER &= ~(1U << ((5U * 2U) + 1U));
}

auto mcal_led_toggle() -> void
{
  #define GPIOA_ODR    (*(volatile unsigned*) 0x40020014U)

  GPIOA_ODR ^= (1U << 5); // toggle PortA.5
}

auto main() -> int
{
  mcal_init();

  for(;;)
  {
    mcal_led_toggle();

    for(volatile unsigned count = 0U; count < 100000U; ++count) { ; }
  }
}
