#include <stdint.h>
#include <string.h>

#include <Mcal/Mcu.h>
#include <Mcal/Reg.h>
#include <Util/C/UtilTimer.h>


static uint64_t TaskTimer01;

/************************* TASK1 *********************************/
void Task01_Init(void);
void Task01_Func(void);

void Task01_Init(void)
{
  /* Enable the clock for GPIO Port F */
  SYSCTL_RCGCGPIO_R = (uint32_t)0x20U;

  /* Set Port F pin 1 as output (this controls all LED) */
  GPIO_PORTF_DIR_R = (uint32_t)0x0EU;

  /* Enable digital function for Port F for rgb leds */
  GPIO_PORTF_DEN_R = (uint32_t)0x0EU;

  /* Set the next timer timeout to be 1s later,             */
  /* Toggling will be sequentially carried out in the task. */
  TaskTimer01 = TimerStart(1U);

}

void Task01_Func(void)
{
  if(TimerTimeout(TaskTimer01))
  {
    TaskTimer01 = TimerStart(1U);

    GPIO_PORTF_DATA_R ^= (uint32_t)0x02UL;
  }
}
