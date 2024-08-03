#include <stdint.h>
#include <string.h>

#include <Mcal/Mcu.h>
#include <Mcal/Reg.h>
#include <Util/C/UtilTimer.h>

static uint64_t TaskTimer02;

/************************* TASK1 *********************************/
void Task01_Init(void);
void Task01_Func(void);

void Task01_Init(void)
{
  /*. Enable GPIO Clock for GPIOB */
  RCC_AHB2ENR |= (1U << 1U);

  /*. Configure PB3 as output */
  GPIOB_MODER |= (1U << 6U);
  GPIOB_MODER &= ~(1U << 7U);

  /* Toggle the LED pin */
  GPIOB_ODR |= (uint32_t) (1UL << 3U);

  /* Set the next timer timeout to be 1s later, */
  /* Toggling will be sequentially carried out in the task. */
  TaskTimer02 = TimerStart(1000U);
}

void Task01_Func(void)
{
  if(TimerTimeout(TaskTimer02))
  {
    TaskTimer02 = TimerStart(1000U);

    /* Toggle the LED pin */
    GPIOB_ODR ^= (uint32_t) (1UL << 3U);
  }
}
