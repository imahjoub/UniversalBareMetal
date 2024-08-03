#include <stdint.h>
#include <Mcal/Mcu.h>
#include <Mcal/Reg.h>
#include <Util/C/UtilTimer.h>

void msDelay(volatile uint32_t count);

// Simple delay function
void msDelay(volatile uint32_t count)
{
  while (count--)
  {
      __asm volatile ("nop"); // No operation (do nothing)
  }
}


int main(void)
{
  /* Configure the System clock and flash */
  SystemInit();
  SetSysClock();

  /*. Enable GPIO Clock for GPIOB */
  RCC_AHB2ENR |= (1U << 1U);

  /*. Configure PB3 as output */
  GPIOB_MODER |= (1U << 6U);
  GPIOB_MODER &= ~(1U << 7U);

  for(;;)
  {
    /* Toggle PB3 to turn the LED on and off */
    GPIOB_ODR ^= (1U << 3U);
    msDelay(1000000U);
  }

  return 0;
}
