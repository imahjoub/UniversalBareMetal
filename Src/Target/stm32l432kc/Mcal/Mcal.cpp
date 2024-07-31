#include <Mcal.h>
#include <Mcu.h>
#include <SysTick.h>


#if defined(__cplusplus)
extern "C"
{
#endif

  void mcal_init(void)
  {
    /* Configure the System clock and flash */
    SystemInit();
    SetSysClock();

    /* Configure systick timer.*/
    SysTick_Init();

    /* Initialize the ports.      */
    /* Enable the clock for GPIOB */
    RCC_AHB2ENR |= (1U << 1U);

    /* Configure GPIOB Pin 3 as output */
    GPIOB_MODER |= (1U << 6U);
    GPIOB_MODER &= ~(1U << 7U);

    /* Switch on the LED.*/
    GPIOB_ODR |= (uint32_t)(1UL << 3U);

    /* Set the next timer timeout to be 1s later,             */
    /* Toggling will be sequentially carried out in the task. */
    TaskTimer01 = TimerStart(1000U);
  }

  void mcal_led_toggle(void)
  {
    if (TimerTimeout(TaskTimer01))
    {
      TaskTimer01 = TimerStart(1000U);

      /* Toggle the LED pin */
      GPIOB_ODR ^= (1U << 3U);
    }
  }

#if defined(__cplusplus)
}
#endif
