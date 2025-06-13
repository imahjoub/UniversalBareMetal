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
  RCC_CR |= (uint32_t)(1UL << 0);

  /* Reset HSEON, CSSON, HSEBYP and PLLON bits */
  RCC_CR &= (uint32_t)((~(1UL << 16)) | (~(1UL << 18))) | (~(1UL << 19)) | (~(1UL << 24));

  /* Reset CFGR register */
  RCC_CFGR = (uint32_t)0x00000000UL;

  /* Reset PLLCFGR register */
  RCC_PLLCFGR = (uint32_t)0x24003010UL;

  /* Disable all interrupts */
  RCC_CIR = (uint32_t)0x00000000UL;

  /* Configure Flash prefetch, Instruction cache, Data cache and wait state (5 wait states) */
  FLASH_ACR = (uint32_t)((1UL << 9) | (1UL << 10) | (5UL << 0));
}

void SetSysClock(void)
{
  /* Enable HSE */
  RCC_CR |= ((uint32_t)(1UL << 16));

  /* Wait till HSE is ready */
  while(!(RCC_CR & ((uint32_t)1UL << 17)))
  {
    __asm volatile("nop");
  }

  /* PWREN: Power interface clock enable */
  RCC_APB1ENR |= (uint32_t)(1UL << 28);

  /* Set HCLK  = sysclk / 1 */
  /* Set PCLK2 = hclk   / 2 */
  /* Set PCLK1 = hclk   / 4 */
  RCC_CFGR |= (uint32_t)((5UL << 10) | (1UL << 15));

  /* Configure the main PLL */
  /* PLL_M = 8        */
  /* PLL_N = 360      */
  /* PLL_P = 0 -> 2   */
  /* PLL_Q = 7        */
  /* SYSCLK = 180 MHz */
  RCC_PLLCFGR = (uint32_t)(8UL << 0) | (360UL << 6) | (0UL << 16) | (1UL << 22) | (7UL << 24);

  /* Enable the main PLL */
  RCC_CR |= (uint32_t)(1UL << 24);

  /* Wait till the main PLL is ready */
  while(!(RCC_CR & (uint32_t)(1UL << 25)))
  {
    __asm volatile("nop");
  }

  /* Select the main PLL as system clock source */
  RCC_CFGR &= (uint32_t)(~(3UL << 0));
  RCC_CFGR |= (uint32_t)(2UL << 0);

  /* Wait till the main PLL is used as system clock source */
  while ((RCC_CFGR & (uint32_t)(0x0CU << 0)) != (8UL << 0))
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

