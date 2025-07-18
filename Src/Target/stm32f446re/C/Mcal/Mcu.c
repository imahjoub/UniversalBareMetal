#include <stdbool.h>

#include <Mcal/Gpt.h>
#include <Mcal/Mcu.h>
#include <Mcal/Gpio.h>

/* Defines */
#define BUTTON_EXTI_LINE     13U
#define NVIC_EXTI15_10_IRQ   40U  /* EXTI lines 10 to 15 use this IRQ */

void SystemInit(void)
{
  /* set coprocessor access control register CP10 and CP11 Full Access */
  SCB_CPACR |= (uint32_t)((uint32_t)(3UL << 20U) | (uint32_t)(3UL << 22U));

  /* Set HSION (internal high-speed clock) enable bit */
  RCC_CR |= (uint32_t)(1UL << 0U);

  /* Reset HSEON, CSSON, HSEBYP and PLLON bits */
  RCC_CR &= (uint32_t)((~(1UL << 16U)) | (~(1UL << 18U))) | (~(1UL << 19U)) | (~(1UL << 24U));

  /* Reset CFGR register */
  RCC_CFGR = (uint32_t)0x00000000UL;

  /* Reset PLLCFGR register */
  RCC_PLLCFGR = (uint32_t)0x24003010UL;

  /* Disable all interrupts */
  RCC_CIR = (uint32_t)0x00000000UL;

  /* Configure Flash prefetch, Instruction cache, Data cache and wait state (5 wait states) */
  FLASH_ACR = (uint32_t)((1UL << 9U) | (1UL << 10U) | (5UL << 0U));
}

void SetSysClock(void)
{
  /* Enable HSE */
  RCC_CR |= ((uint32_t)(1UL << 16U));

  /* Wait till HSE is ready */
  while(!(RCC_CR & ((uint32_t)1UL << 17U)))
  {
    __asm volatile("nop");
  }

  /* PWREN: Power interface clock enable */
  RCC_APB1ENR |= (uint32_t)(1UL << 28U);

  /* Set HCLK  = sysclk / 1 */
  /* Set PCLK2 = hclk   / 2 */
  /* Set PCLK1 = hclk   / 4 */     // for WWDG  set --> (7UL << 10U)  for hclk / 16
  RCC_CFGR |= (uint32_t)((5UL << 10U) | (1UL << 15U));

  /* HSE division factor for RTC clock */
  /* Devide by 16 to get 1 MHz for RTC */
  RCC_CFGR |= (uint32_t)(1UL << 20U);

  /* Configure the main PLL */
  /* PLL_M = 8              */
  /* PLL_N = 360            */
  /* PLL_P = 0 -> 2         */
  /* PLL_Q = 7              */
  /* SYSCLK = 180 MHz       */
  RCC_PLLCFGR = (uint32_t)(8UL << 0U) | (360UL << 6U) | (0UL << 16U) | (1UL << 22U) | (7UL << 24U);

  /* Enable the main PLL */
  RCC_CR |= (uint32_t)(1UL << 24U);

  /* Wait till the main PLL is ready */
  while(!(RCC_CR & (uint32_t)(1UL << 25U)))
  {
    __asm volatile("nop");
  }

  /* Select the main PLL as system clock source */
  RCC_CFGR &= (uint32_t)(~(3UL << 0U));
  RCC_CFGR |= (uint32_t)(2UL << 0U);

  /* Wait till the main PLL is used as system clock source */
  while ((RCC_CFGR & (uint32_t)(0x0CU << 0U)) != (8UL << 0U))
  {
  }
}



void EXTI_Init(void)
{
  // Enable SYSCFG clock */
  RCC_APB2ENR |= (1UL << 14U);

  // Set EXTI line for USER_BUTTON */
  SYSCFG_EXTICR4 &= (uint32_t)(~(0xF << ((USER_BUTTON - 12U) * 4U)));
  SYSCFG_EXTICR4 |=           (0x2UL << ((USER_BUTTON - 12U) * 4U));

  // Configure EXTI for falling edge trigger */
  EXTI_IMR  |= (1UL << BUTTON_EXTI_LINE);
  EXTI_FTSR |= (1UL << BUTTON_EXTI_LINE);

  // Enable EXTI line interrupt */
  NVIC_ISER1 |= (1UL << (NVIC_EXTI15_10_IRQ - 32U));

}

