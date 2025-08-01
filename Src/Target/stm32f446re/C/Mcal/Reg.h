#ifndef REG_2025_06_12_H
  #define REG_2025_06_12_H

  #include <stdint.h>

  /* Base addresses for peripheral registers */
  #define ADC1_BASE             0x40012000UL
  #define DMA1_BASE             0x40026000UL
  #define EXTI_BASE             0x40013C00UL
  #define GPIOA_BASE            0x40020000UL
  #define GPIOC_BASE            0x40020800UL
  #define FLASH_BASE            0x40023C00UL
  #define IWDG_BASE             0x40003000UL
  #define SPI_BASE              0x40013000UL
  #define SYSCFG_BASE           0x40013800UL
  #define PWR_BASE              0x40007000UL
  #define RCC_BASE              0x40023800UL
  #define RTC_BASE              0x40002800UL
  #define NVIC_ISER_BASE        0xE000E100UL
  #define SCB_BASE              0xE000ED00UL
  #define STK_BASE              0xE000E010UL
  #define TIM2_BASE             0x40000000UL
  #define WWDG_BASE             0x40002C00UL


  /* ADC1 registers */
  #define ADC1_SR              (*(volatile uint32_t*)(ADC1_BASE + 0x00UL))
  #define ADC1_CR2             (*(volatile uint32_t*)(ADC1_BASE + 0x08UL))
  #define ADC1_SQR3            (*(volatile uint32_t*)(ADC1_BASE + 0x34UL))
  #define ADC1_DR              (*(volatile uint32_t*)(ADC1_BASE + 0x4CUL))

  /* NVIC registers */
  #define NVIC_ISER0           (*(volatile uint32_t*)0xE000E100UL)
  #define NVIC_ISER1           (*(volatile uint32_t*)(NVIC_ISER_BASE + 0x04UL))

  /* EXTI registers */
  #define EXTI_IMR             (*(volatile uint32_t*)(EXTI_BASE   + 0x00UL))
  #define EXTI_EMR             (*(volatile uint32_t*)(EXTI_BASE   + 0x04UL))
  #define EXTI_RTSR            (*(volatile uint32_t*)(EXTI_BASE   + 0x08UL))
  #define EXTI_FTSR            (*(volatile uint32_t*)(EXTI_BASE   + 0x0CUL))
  #define EXTI_PR              (*(volatile uint32_t*)(EXTI_BASE   + 0x14UL))

  /* SYSCFG registers */
  #define SYSCFG_EXTICR4       (*(volatile uint32_t*)(SYSCFG_BASE + 0x14UL))

  /* IWDG Registers */
  #define IWDG_KR              (*(volatile uint32_t*)(IWDG_BASE + 0x00UL))
  #define IWDG_PR              (*(volatile uint32_t*)(IWDG_BASE + 0x04UL))
  #define IWDG_RLR             (*(volatile uint32_t*)(IWDG_BASE + 0x08UL))
  #define IWDG_SR              (*(volatile uint32_t*)(IWDG_BASE + 0x0CUL))

  /* WWDG Registers */
  #define WWDG_CR              (*(volatile uint32_t*)(WWDG_BASE + 0x00UL))
  #define WWDG_CFR             (*(volatile uint32_t*)(WWDG_BASE + 0x04UL))
  #define WWDG_SR              (*(volatile uint32_t*)(WWDG_BASE + 0x08UL))

  /* SCB registers */
  #define SCB_CPACR            (*(volatile uint32_t*)(SCB_BASE + 0x88UL))
  #define SCB_SCR              (*(volatile uint32_t*)(SCB_BASE + 0x10UL))

  /* SysTick registers */
  #define STK_CTRL             (*(volatile uint32_t*)(STK_BASE + 0x00UL))
  #define STK_LOAD             (*(volatile uint32_t*)(STK_BASE + 0x04UL))
  #define STK_VAL              (*(volatile uint32_t*)(STK_BASE + 0x08UL))

  /* RCC Registers */
  #define RCC_CR               (*(volatile uint32_t*)(RCC_BASE + 0x00UL))
  #define RCC_PLLCFGR          (*(volatile uint32_t*)(RCC_BASE + 0x04UL))
  #define RCC_CFGR             (*(volatile uint32_t*)(RCC_BASE + 0x08UL))
  #define RCC_AHB1ENR          (*(volatile uint32_t*)(RCC_BASE + 0x30UL))
  #define RCC_CIR              (*(volatile uint32_t*)(RCC_BASE + 0x0CUL))
  #define RCC_APB1ENR          (*(volatile uint32_t*)(RCC_BASE + 0x40UL))
  #define RCC_APB2ENR          (*(volatile uint32_t*)(RCC_BASE + 0x44UL))
  #define RCC_BDCR             (*(volatile uint32_t*)(RCC_BASE + 0x70UL))
  #define RCC_CSR              (*(volatile uint32_t*)(RCC_BASE + 0x74UL))

  /* PWR registers */
  #define PWR_CR               (*(volatile uint32_t*)(PWR_BASE + 0x00UL))
  #define PWR_CSR              (*(volatile uint32_t*)(PWR_BASE + 0x04UL))

  /* FLASH registers */
  #define FLASH_ACR            (*(volatile uint32_t*)(FLASH_BASE + 0x00UL))

  /* SPI registers */
  #define SPI_CR1              (*(volatile uint32_t*)(SPI_BASE + 0x00UL))
  #define SPI_CR2              (*(volatile uint32_t*)(SPI_BASE + 0x04UL))
  #define SPI_SR               (*(volatile uint32_t*)(SPI_BASE + 0x08UL))
  #define SPI_DR               (*(volatile uint32_t*)(SPI_BASE + 0x0CUL))
  #define SPI_CRCPR            (*(volatile uint32_t*)(SPI_BASE + 0x10UL))
  #define SPI_RXCRCR           (*(volatile uint32_t*)(SPI_BASE + 0x14UL))
  #define SPI_TXCRCR           (*(volatile uint32_t*)(SPI_BASE + 0x18UL))

  /* GPIOA registers */
  #define GPIOA_MODER          (*(volatile uint32_t*)(GPIOA_BASE + 0x00UL))
  #define GPIOA_OSPEEDR        (*(volatile uint32_t*)(GPIOA_BASE + 0x08UL))
  #define GPIOA_PUPDR          (*(volatile uint32_t*)(GPIOA_BASE + 0x0CUL))
  #define GPIOA_ODR            (*(volatile uint32_t*)(GPIOA_BASE + 0x14UL))
  #define GPIOA_AFRL           (*(volatile uint32_t*)(GPIOA_BASE + 0x20UL))

  /* GPIOC registers */
  #define GPIOC_MODER          (*(volatile uint32_t*)(GPIOC_BASE + 0x00UL))
  #define GPIOC_PUPDR          (*(volatile uint32_t*)(GPIOC_BASE + 0x0CUL))
  #define GPIOC_IDR            (*(volatile uint32_t*)(GPIOC_BASE + 0x10UL))

  /* TIM2 registers */
  #define TIM2_CR1             (*(volatile uint32_t*)(TIM2_BASE + 0x00UL))
  #define TIM2_CR2             (*(volatile uint32_t*)(TIM2_BASE + 0x04UL))
  #define TIM2_SMCR            (*(volatile uint32_t*)(TIM2_BASE + 0x08UL))
  #define TIM2_DIER            (*(volatile uint32_t*)(TIM2_BASE + 0x0CUL))
  #define TIM2_SR              (*(volatile uint32_t*)(TIM2_BASE + 0x10UL))
  #define TIM2_EGR             (*(volatile uint32_t*)(TIM2_BASE + 0x14UL))
  #define TIM2_CCMR1           (*(volatile uint32_t*)(TIM2_BASE + 0x18UL))
  #define TIM2_CCER            (*(volatile uint32_t*)(TIM2_BASE + 0x20UL))
  #define TIM2_CNT             (*(volatile uint32_t*)(TIM2_BASE + 0x24UL))
  #define TIM2_PSC             (*(volatile uint32_t*)(TIM2_BASE + 0x28UL))
  #define TIM2_ARR             (*(volatile uint32_t*)(TIM2_BASE + 0x2CUL))
  #define TIM2_CCR1            (*(volatile uint32_t*)(TIM2_BASE + 0x34UL))
  #define TIM2_CCR2            (*(volatile uint32_t*)(TIM2_BASE + 0x38UL))

  /* DMA1 registers */
  #define DMA1_LISR            (*(volatile uint32_t*)(DMA1_BASE + 0x00UL))
  #define DMA1_HISR            (*(volatile uint32_t*)(DMA1_BASE + 0x04UL))
  #define DMA1_LIFCR           (*(volatile uint32_t*)(DMA1_BASE + 0x08UL))
  #define DMA1_HIFCR           (*(volatile uint32_t*)(DMA1_BASE + 0x0CUL))
  #define DMA1_STREAM5_CR      (*(volatile uint32_t*)(DMA1_BASE + 0x88UL))
  #define DMA1_STREAM5_NDTR    (*(volatile uint32_t*)(DMA1_BASE + 0x8CUL))
  #define DMA1_STREAM5_PAR     (*(volatile uint32_t*)(DMA1_BASE + 0x90UL))
  #define DMA1_STREAM5_M0AR    (*(volatile uint32_t*)(DMA1_BASE + 0x9CUL))
  #define DMA1_STREAM6_CR      (*(volatile uint32_t*)(DMA1_BASE + 0xA0UL))
  #define DMA1_STREAM6_NDTR    (*(volatile uint32_t*)(DMA1_BASE + 0xA4UL))
  #define DMA1_STREAM6_PAR     (*(volatile uint32_t*)(DMA1_BASE + 0xA8UL))
  #define DMA1_STREAM6_M0AR    (*(volatile uint32_t*)(DMA1_BASE + 0xB4UL))

  /* RTC registers */
  #define RTC_TR               (*(volatile uint32_t*)(RTC_BASE + 0x00UL))
  #define RTC_DR               (*(volatile uint32_t*)(RTC_BASE + 0x04UL))
  #define RTC_CR               (*(volatile uint32_t*)(RTC_BASE + 0x08UL))
  #define RTC_ISR              (*(volatile uint32_t*)(RTC_BASE + 0x0CUL))
  #define RTC_PRER             (*(volatile uint32_t*)(RTC_BASE + 0x10UL))
  #define RTC_WUTR             (*(volatile uint32_t*)(RTC_BASE + 0x14UL))
  #define RTC_WPR              (*(volatile uint32_t*)(RTC_BASE + 0x24UL))
  #define RTC_ALRMAR           (*(volatile uint32_t*)(RTC_BASE + 0x1CUL))
  #define RTC_ALRMBR           (*(volatile uint32_t*)(RTC_BASE + 0x20UL))


#endif /* REG_2025_06_12_H */

