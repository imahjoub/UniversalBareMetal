#define RCC_AHB1ENR (*(volatile unsigned*) 0x40023830U)
#define GPIOA_MODER (*(volatile unsigned*) 0x40020000U)
#define GPIOA_ODR   (*(volatile unsigned*) 0x40020014U)

int main()
{
  RCC_AHB1ENR |= 1U;

  GPIOA_MODER |= (1U << (5U * 2U));
  GPIOA_MODER &= ~(1U << ((5U * 2U) + 1U));

  for(;;)
  {
    GPIOA_ODR ^= (1U << 5); // toggle PortA.5

    for(volatile unsigned count = 0U; count < 100000U; ++count) { ; }
  }

  return 0;
}
