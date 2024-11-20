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
  /* Enable USERCC2 in RCC2 to use RCC2 for advanced features */
  SYSCTL_RCC2_R |= (uint32_t)(1UL << 31U);   /* Set bit 31 to enable RCC2 */

   /* Bypass the PLL while initializing */
  SYSCTL_RCC2_R |= (uint32_t)(1UL << 11U);   /* Set bit 11 to bypass PLL */

  /* Set the crystal (attached to the main oscillator) value and oscillator source for 16 MHz */
  SYSCTL_RCC_R &= (uint32_t)(~(0x7C0UL));     /* Clear bits 10:6 for XTAL */
  SYSCTL_RCC_R |= (uint32_t)(0x15U << 6U);    /* Set XTAL value to 0x15 (16 MHz) */

  /* Select main oscillator (OSCSRC2 = 0) */
  SYSCTL_RCC2_R &= (uint32_t)(~(0x70UL));

  /* Power up the PLL */
  SYSCTL_RCC2_R &= ~(1UL << 13U);

  /* 5. Set the system divider for 80 MHz clock */
  SYSCTL_RCC2_R |= (uint32_t)(1UL << 30U);        /* Set bit 30 to use DIV400 (400 MHz PLL output) */
  SYSCTL_RCC2_R &= (uint32_t)(~(0x1FC00000UL));   /* Clear bits 28:22 for SYSDIV2 */
  SYSCTL_RCC2_R |= (uint32_t)(0x04UL << 22U);    /* Set SYSDIV2 to 4, so 400 MHz / (4 + 1) = 80 MHz */

  /* Wait for the PLL to lock by polling PLLLRIS */
  while ((SYSCTL_RIS_R & (1UL << 6U)) == 0U)
  {
    /* Wait until bit 6 (PLLLRIS) is set, indicating PLL has locked */
  }

  /* Enable the PLL */
  SYSCTL_RCC2_R &= (uint32_t)(~(1UL << 11U));   /* Clear bit 11 to use PLL */

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

