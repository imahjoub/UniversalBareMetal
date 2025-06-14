#include <stdint.h>
#include <string.h>

#include <Mcal/Gpio.h>
#include <Mcal/Mcu.h>
#include <Mcal/Reg.h>

#include <Util/C/UtilTimer.h>

static uint64_t  TaskTimer01;

/************************* TASK1 *********************************/
void Task01_Init(void);
void Task01_Func(void);

void Task01_Init(void)
{
  /* Enable the clock for GPIOA */
  RCC_AHB1ENR |= (1UL << 0U);

  /* Configure GPIOA Pin 5 as output */
  GPIOA_MODER |= (1UL << 10U);

  /* Set the next timer timeout to be 1s later, */
  /* Toggling will be sequentially carried out in the task. */
  TaskTimer01 = TimerStart(1000U);
}

void Task01_Func(void)
{
  if(TimerTimeout(TaskTimer01))
  {
    /* 1s delay */
    TaskTimer01 = TimerStart(1000U);

    /* Toggle the LED pinAdd commentMore actions */
    GPIOA_ODR ^= (1UL << 5U);
  }
}

