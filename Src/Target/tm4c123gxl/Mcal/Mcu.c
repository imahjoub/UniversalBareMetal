#include <Mcal/Mcu.h>
#include <Mcal/Reg.h>

static void DisableInterrupts(void);
static void EnableInterrupts(void);



void SystemInit(void)
{
  /* Set coprocessor access control register CP10 and CP11 Full Access (Enable floating point unit) */
  NVIC_CPAC_R |= (uint32_t)((uint32_t)(3UL << 20U) | (uint32_t)(3UL << 22U));

  /* Reset RCC register */
  SYSCTL_RCC_R |= (uint32_t)0X07803AD1UL;

  /* Reset RCC2 register */
  SYSCTL_RCC_R |= (uint32_t)0x07C06810UL;

  /* Disable all interrupts */
  DisableInterrupts();

}

void SetSysClock(void)
{
  /* Use RCC2 for advanced features */
  SYSCTL_RCC2_R |= (uint32_t)SYSCTL_RCC2_USERCC2;

  /* Bypass PLL while initializing */
  SYSCTL_RCC2_R |= (uint32_t)SYSCTL_RCC2_BYPASS2;

  /* Set crystal value and oscillator source */
  SYSCTL_RCC_R  &= (uint32_t)(~0x000007C0UL);              /* Clear XTAL field               */
  SYSCTL_RCC_R  += (uint32_t)SYSCTL_RCC_XTAL_16MHZ;        /* Set XTAL = 16 MHz              */
  SYSCTL_RCC2_R &= (uint32_t)(~SYSCTL_RCC2_OSCSRC2_M);     /* Clear oscillator source field  */
  SYSCTL_RCC2_R += (uint32_t)SYSCTL_RCC2_OSCSRC2_MO;       /* Set oscillator source to main  */

  /* Activate PLL by clearing PWRDN */
  SYSCTL_RCC2_R &= (uint32_t)(~SYSCTL_RCC2_PWRDN2);

  /* Set system divider and enable 400 MHz PLL */
  SYSCTL_RCC2_R |= (uint32_t)SYSCTL_RCC2_DIV400;      /* Use 400 MHz PLL */
  SYSCTL_RCC2_R  = (uint32_t)((SYSCTL_RCC2_R & (uint32_t)(~0x1FC00000UL)) + ((uint32_t)(4UL << 22U)));  /* 400 / (4+1) = 80 MHz */

  /* Wait for the PLL to lock */
  while((SYSCTL_RIS_R & SYSCTL_RIS_PLLLRIS) == 0) { /* Do nothing */}

  /* Enable use of PLL by clearing BYPASS */
  SYSCTL_RCC2_R &= (uint32_t)(~SYSCTL_RCC2_BYPASS2);

  /* set the SysTick interrupt priority (highest) */
  NVIC_SYS_PRI3_R &= ~0xE0000000;

  EnableInterrupts();
}


static void DisableInterrupts(void)
{
  __asm(" CPSID I");  // Clear PRIMASK to disable all interrupts
}

static void EnableInterrupts(void)
{
  __asm(" CPSIE I");  // Set PRIMASK to enable all interrupts
}

