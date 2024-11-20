#include <Mcal/Gpt.h>
#include <Mcal/Reg.h>
#include <Mcal/SysTick.h>

void SysTick_Init(void)
{
  /* Disable SysTick during setup */
  NVIC_ST_CTRL_R = (uint32_t)0x00000000UL;

  /* Set reload register to achieve a 1 tick */
  /* the systick timer interrupt will occur after one second */
  NVIC_ST_RELOAD_R = (uint32_t)(80000000 - 1UL);

  /* Set the initial value to zero */
  NVIC_ST_CURRENT_R |= (uint32_t)0UL;

  /* Enable SysTick with system clock and enable interrupt */
  NVIC_ST_CTRL_R |= (uint32_t)(0x07UL);

}
