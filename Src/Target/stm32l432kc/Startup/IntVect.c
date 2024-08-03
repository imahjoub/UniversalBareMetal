/*     Stack size      */
#define STACK_SIZE       0x00000400


/* ----------------------------------------------------------------------------------- */
/*  Extern functions                                                                   */
/* ----------------------------------------------------------------------------------- */
extern void __my_startup           (void);
extern void __initial_stack_pointer(void);

/* ----------------------------------------------------------------------------------- */
/*  Functions prototype                                                                */
/* ----------------------------------------------------------------------------------- */
static void Undefined_Handler      (void);

void Reset_Handler                 (void) __attribute__((weak, alias("Undefined_Handler")));
void NMI_Handler                   (void) __attribute__((weak, alias("Undefined_Handler")));
void HardFault_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void MemManage_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void BusFault_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void UsageFault_Handler            (void) __attribute__((weak, alias("Undefined_Handler")));
void SVC_Handler                   (void) __attribute__((weak, alias("Undefined_Handler")));
void DebugMon_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void PendSV_Handler                (void) __attribute__((weak, alias("Undefined_Handler")));
void SysTick_Handler               (void) __attribute__((weak, alias("Undefined_Handler")));
void WWDG_IRQHandler               (void) __attribute__((weak, alias("Undefined_Handler")));
void PVD_PVM_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void TAMP_STAMP_IRQHandler         (void) __attribute__((weak, alias("Undefined_Handler")));
void RTC_WKUP_IRQHandler           (void) __attribute__((weak, alias("Undefined_Handler")));
void FLASH_IRQHandler              (void) __attribute__((weak, alias("Undefined_Handler")));
void RCC_IRQHandler                (void) __attribute__((weak, alias("Undefined_Handler")));
void EXTI0_IRQHandler              (void) __attribute__((weak, alias("Undefined_Handler")));
void EXTI1_IRQHandler              (void) __attribute__((weak, alias("Undefined_Handler")));
void EXTI2_IRQHandler              (void) __attribute__((weak, alias("Undefined_Handler")));
void EXTI3_IRQHandler              (void) __attribute__((weak, alias("Undefined_Handler")));
void EXTI4_IRQHandler              (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA1_Channel1_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA1_Channel2_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA1_Channel3_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA1_Channel4_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA1_Channel5_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA1_Channel6_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA1_Channel7_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC1_IRQHandler               (void) __attribute__((weak, alias("Undefined_Handler")));
void CAN1_TX_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void CAN1_RX0_IRQHandler           (void) __attribute__((weak, alias("Undefined_Handler")));
void CAN1_RX1_IRQHandler           (void) __attribute__((weak, alias("Undefined_Handler")));
void CAN1_SCE_IRQHandler           (void) __attribute__((weak, alias("Undefined_Handler")));
void EXTI9_5_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void TIM1_BRK_TIM15_IRQHandler     (void) __attribute__((weak, alias("Undefined_Handler")));
void TIM1_UP_TIM16_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void TIM1_TRG_COM_IRQHandler       (void) __attribute__((weak, alias("Undefined_Handler")));
void TIM1_CC_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void TIM2_IRQHandler               (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C1_EV_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C1_ER_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void SPI1_IRQHandler               (void) __attribute__((weak, alias("Undefined_Handler")));
void USART1_IRQHandler             (void) __attribute__((weak, alias("Undefined_Handler")));
void USART2_IRQHandler             (void) __attribute__((weak, alias("Undefined_Handler")));
void EXTI15_10_IRQHandler          (void) __attribute__((weak, alias("Undefined_Handler")));
void RTC_Alarm_IRQHandler          (void) __attribute__((weak, alias("Undefined_Handler")));
void SPI3_IRQHandler               (void) __attribute__((weak, alias("Undefined_Handler")));
void TIM6_DAC_IRQHandler           (void) __attribute__((weak, alias("Undefined_Handler")));
void TIM7_IRQHandler               (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA2_Channel1_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA2_Channel2_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA2_Channel3_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA2_Channel4_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA2_Channel5_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void COMP_IRQHandler               (void) __attribute__((weak, alias("Undefined_Handler")));
void LPTIM1_IRQHandler             (void) __attribute__((weak, alias("Undefined_Handler")));
void LPTIM2_IRQHandler             (void) __attribute__((weak, alias("Undefined_Handler")));
void USB_IRQHandler                (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA2_Channel6_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void DMA2_Channel7_IRQHandler      (void) __attribute__((weak, alias("Undefined_Handler")));
void LPUART1_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void QUADSPI_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C3_EV_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C3_ER_IRQHandler            (void) __attribute__((weak, alias("Undefined_Handler")));
void SAI1_IRQHandler               (void) __attribute__((weak, alias("Undefined_Handler")));
void SWPMI1_IRQHandler             (void) __attribute__((weak, alias("Undefined_Handler")));
void TSC_IRQHandler                (void) __attribute__((weak, alias("Undefined_Handler")));
void RNG_IRQHandler                (void) __attribute__((weak, alias("Undefined_Handler")));
void FPU_IRQHandler                (void) __attribute__((weak, alias("Undefined_Handler")));
void CRS_IRQHandler                (void) __attribute__((weak, alias("Undefined_Handler")));

/* ----------------------------------------------------------------------------------- */
/*  Functions defintion                                                                */
/* ----------------------------------------------------------------------------------- */
static void Undefined_Handler(void)
{
  while(1) { __asm("NOP"); }
}


/* ----------------------------------------------------------------------------------- */
/*  Types definition                                                                   */
/* ----------------------------------------------------------------------------------- */
typedef void (*isr_type)(void);


const volatile isr_type __isr_vector[] __attribute__ ((section(".isr_vector"))) =
{
  /* --------- Cortex-M4 Processor Exceptions ----------------------------------- */
  __initial_stack_pointer,    /* The initial stack pointer                        */
  __my_startup,               /* Reset Handler                                    */
  NMI_Handler,                /* NMI Handler                                      */
  HardFault_Handler,          /* Hard Fault Handler                               */
  MemManage_Handler,          /* MPU Fault Handler                                */
  BusFault_Handler,           /* Bus Fault Handler                                */
  UsageFault_Handler,         /* Usage Fault Handler                              */
  0,                          /* Reserved                                         */
  0,                          /* Reserved                                         */
  0,                          /* Reserved                                         */
  0,                          /* Reserved                                         */
  SVC_Handler,                /* SVCall Handler                                   */
  DebugMon_Handler,           /* Debug Monitor Handler                            */
  0,                          /* Reserved                                         */
  PendSV_Handler,             /* PendSV Handler                                   */
  SysTick_Handler,            /* SysTick Handler                                  */

  /* --------- STM32 specific Interrupt ----------------------------------------- */
  WWDG_IRQHandler,            /*  0: */
  PVD_PVM_IRQHandler,         /*  1: */
  TAMP_STAMP_IRQHandler,      /*  2: */
  RTC_WKUP_IRQHandler,        /*  3: */
  FLASH_IRQHandler,           /*  4: */
  RCC_IRQHandler,             /*  5: */
  EXTI0_IRQHandler,           /*  6: */
  EXTI1_IRQHandler,           /*  7: */
  EXTI2_IRQHandler,           /*  8: */
  EXTI3_IRQHandler,           /*  9: */
  EXTI4_IRQHandler,           /* 10: */
  DMA1_Channel1_IRQHandler,   /* 11: */
  DMA1_Channel2_IRQHandler,   /* 12: */
  DMA1_Channel3_IRQHandler,   /* 13: */
  DMA1_Channel4_IRQHandler,   /* 14: */
  DMA1_Channel5_IRQHandler,   /* 15: */
  DMA1_Channel6_IRQHandler,   /* 16: */
  DMA1_Channel7_IRQHandler,   /* 17: */
  ADC1_IRQHandler,            /* 18: */
  CAN1_TX_IRQHandler,         /* 19: */
  CAN1_RX0_IRQHandler,        /* 20: */
  CAN1_RX1_IRQHandler,        /* 21: */
  CAN1_SCE_IRQHandler,        /* 22: */
  EXTI9_5_IRQHandler,         /* 23: */
  TIM1_BRK_TIM15_IRQHandler,  /* 24: */
  TIM1_UP_TIM16_IRQHandler,   /* 25: */
  TIM1_TRG_COM_IRQHandler,    /* 26: */
  TIM1_CC_IRQHandler,         /* 27: */
  TIM2_IRQHandler,            /* 28: */
  0,                          /* 29: */
  0,                          /* 30: */
  I2C1_EV_IRQHandler,         /* 31: */
  I2C1_ER_IRQHandler,         /* 32: */
  0,                          /* 33: */
  0,                          /* 34: */
  SPI1_IRQHandler,            /* 35: */
  0,                          /* 36: */
  USART1_IRQHandler,          /* 37: */
  USART2_IRQHandler,          /* 38: */
  0,                          /* 39: */
  EXTI15_10_IRQHandler,       /* 40: */
  RTC_Alarm_IRQHandler,       /* 41: */
  0,                          /* 42: */
  0,                          /* 43: */
  0,                          /* 44: */
  0,                          /* 45: */
  0,                          /* 46: */
  0,                          /* 47: */
  0,                          /* 48: */
  0,                          /* 49: */
  0,                          /* 50: */
  SPI3_IRQHandler,            /* 51: */
  0,                          /* 52: */
  0,                          /* 53: */
  TIM6_DAC_IRQHandler,        /* 54: */
  TIM7_IRQHandler,            /* 55: */
  DMA2_Channel1_IRQHandler,   /* 56: */
  DMA2_Channel2_IRQHandler,   /* 57: */
  DMA2_Channel3_IRQHandler,   /* 58: */
  DMA2_Channel4_IRQHandler,   /* 59: */
  DMA2_Channel5_IRQHandler,   /* 60: */
  0,                          /* 61: */
  0,                          /* 62: */
  0,                          /* 63: */
  COMP_IRQHandler,            /* 64: */
  LPTIM1_IRQHandler,          /* 65: */
  LPTIM2_IRQHandler,          /* 66: */
  USB_IRQHandler,             /* 67: */
  DMA2_Channel6_IRQHandler,   /* 68: */
  DMA2_Channel7_IRQHandler,   /* 69: */
  LPUART1_IRQHandler,         /* 70: */
  QUADSPI_IRQHandler,         /* 71: */
  I2C3_EV_IRQHandler,         /* 72: */
  I2C3_ER_IRQHandler,         /* 73: */
  SAI1_IRQHandler,            /* 74: */
  0,                          /* 75: */
  SWPMI1_IRQHandler,          /* 76: */
  TSC_IRQHandler,             /* 77: */
  0,                          /* 78: */
  0,                          /* 79: */
  RNG_IRQHandler,             /* 80: */
  FPU_IRQHandler,             /* 81: */
  CRS_IRQHandler              /* 82: */
};
#if 0
 Window WatchDog Interrupt                                         */
 PVD/PVM3/PVM4 through EXTI Line detection Interrupts              */
 Tamper and TimeStamp interrupts through the EXTI line             */
 RTC Wakeup interrupt through the EXTI line                        */
 FLASH global Interrupt                                            */
 RCC global Interrupt                                              */
 EXTI Line0 Interrupt                                              */
 EXTI Line1 Interrupt                                              */
 EXTI Line2 Interrupt                                              */
 EXTI Line3 Interrupt                                              */
 EXTI Line4 Interrupt                                              */
 DMA1 Channel 1 global Interrupt                                   */
 DMA1 Channel 2 global Interrupt                                   */
 DMA1 Channel 3 global Interrupt                                   */
 DMA1 Channel 4 global Interrupt                                   */
 DMA1 Channel 5 global Interrupt                                   */
 DMA1 Channel 6 global Interrupt                                   */
 DMA1 Channel 7 global Interrupt                                   */
 ADC1 global Interrupt                                             */
 CAN1 TX Interrupt                                                 */
 CAN1 RX0 Interrupt                                                */
 CAN1 RX1 Interrupt                                                */
 CAN1 SCE Interrupt                                                */
 External Line[9:5] Interrupts                                     */
 TIM1 Break interrupt and TIM15 global interrupt                   */
 TIM1 Update Interrupt and TIM16 global interrupt                  */
 TIM1 Trigger and Commutation Interrupt                            */
 TIM1 Capture Compare Interrupt                                    */
 TIM2 global Interrupt                                             */
 I2C1 Event Interrupt                                              */
 I2C1 Error Interrupt                                              */
 SPI1 global Interrupt                                             */
 USART1 global Interrupt                                           */
 USART2 global Interrupt                                           */
 External Line[15:10] Interrupts                                   */
 RTC Alarm (A and B) through EXTI Line Interrupt                   */
 SPI3 global Interrupt                                             */
 TIM6 global and DAC1&2 underrun error  interrupts                 */
 TIM7 global interrupt                                             */
 DMA2 Channel 1 global Interrupt                                   */
 DMA2 Channel 2 global Interrupt                                   */
 DMA2 Channel 3 global Interrupt                                   */
 DMA2 Channel 4 global Interrupt                                   */
 DMA2 Channel 5 global Interrupt                                   */
 COMP1 and COMP2 Interrupts                                        */
 LP TIM1 interrupt                                                 */
 LP TIM2 interrupt                                                 */
 USB event Interrupt                                               */
 DMA2 Channel 6 global interrupt                                   */
 DMA2 Channel 7 global interrupt                                   */
 LP UART1 interrupt                                                */
 Quad SPI global interrupt                                         */
 I2C3 event interrupt                                              */
 I2C3 error interrupt                                              */
 Serial Audio Interface 1 global interrupt                         */
 Serial Wire Interface 1 global interrupt                          */
 Touch Sense Controller global interrupt                           */
 RNG global interrupt                                              */
 FPU global interrupt                                              */
 CRS global interrupt
#endif
