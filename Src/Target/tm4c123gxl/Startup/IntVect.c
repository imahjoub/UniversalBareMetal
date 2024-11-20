/* ----------------------------------------------------------------------------------- */
// IntVect.c The interrupts vector table.
//
/* ----------------------------------------------------------------------------------- */
#include <stdint.h>

/*     Stack size      */
#define STACK_SIZE       0x00000400

/*     Heap size      */
#define HEAP_SIZE        0x00000000

/* ----------------------------------------------------------------------------------- */
/*  Extern functions                                                                   */
/* ----------------------------------------------------------------------------------- */
extern void __my_startup           (void);
extern void __initial_stack_pointer(void);

/* ----------------------------------------------------------------------------------- */
/*  Functions prototype                                                                */
/* ----------------------------------------------------------------------------------- */
static void Undefined_Handler  (void);

void NMI_Handler               (void) __attribute__((weak, alias("Undefined_Handler")));
void HardFault_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void MemManage_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void BusFault_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void UsageFault_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void SVC_Handler               (void) __attribute__((weak, alias("Undefined_Handler")));
void DebugMon_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void PendSV_Handler            (void) __attribute__((weak, alias("Undefined_Handler")));
void SysTick_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortA_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortB_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortC_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortD_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortE_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void UART0_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void UART1_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void SSI0_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C0_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM0Fault_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM0Generator0_Handler    (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM0Generator1_Handler    (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM0Generator2_Handler    (void) __attribute__((weak, alias("Undefined_Handler")));
void Quadrature0_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC0Seq0_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC0Seq1_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC0Seq2_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC0Seq3_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void WDT_Handler               (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer0A_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer0B_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer1A_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer1B_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer2A_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer2B_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Comp0_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void Comp1_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void Comp2_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void SysCtl_Handler            (void) __attribute__((weak, alias("Undefined_Handler")));
void FlashCtl_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortF_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortG_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortH_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void UART2_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void SSI1_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer3A_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer3B_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C1_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void Quadrature1_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void CAN0_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void CAN1_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void CAN2_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void Ethernet_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void Hibernate_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void USB0_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM0Generator3_Handler    (void) __attribute__((weak, alias("Undefined_Handler")));
void uDMA_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void uDMA_Error                (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC1Seq0_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC1Seq1_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC1Seq2_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void ADC1Seq3_Handler          (void) __attribute__((weak, alias("Undefined_Handler")));
void I2S0_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void ExtBus_Handler            (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortJ_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortK_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortL_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void SSI2_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void SSI3_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void UART3_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void UART4_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void UART5_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void UART6_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void UART7_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C2_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C3_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer4A_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer4B_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer5A_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void Timer5B_Handler           (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer0A_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer0B_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer1A_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer1B_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer2A_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer2B_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer3A_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer3B_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer4A_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer4B_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer5A_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void WideTimer5B_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void FPU_Handler               (void) __attribute__((weak, alias("Undefined_Handler")));
void PECI0_Handler             (void) __attribute__((weak, alias("Undefined_Handler")));
void LPC0_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C4_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void I2C5_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortM_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortN_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void Quadrature2_Handler       (void) __attribute__((weak, alias("Undefined_Handler")));
void Fan0_Handler              (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortP_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortP1_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortP2_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortP3_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortP4_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortP5_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortP6_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortP7_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortQ_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortQ1_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortQ2_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortQ3_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortQ4_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortQ5_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortQ6_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortQ7_Handler        (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortR_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void GPIOPortS_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM1Generator0_Handler    (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM1Generator1_Handler    (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM1Generator2_Handler    (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM1Generator3_Handler    (void) __attribute__((weak, alias("Undefined_Handler")));
void PWM1Fault_Handler         (void) __attribute__((weak, alias("Undefined_Handler")));


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

/* ----------------------------------------------------------------------------------- */
/*  Interrupt vector table                                                             */
/* ----------------------------------------------------------------------------------- */
__attribute__ ((section(".isr_vector"))) void (* const g_pfnVectors[])(void) =
{
  /* -----------------------------Core Exceptions-------------------------------------- */
  __initial_stack_pointer,     /* The initial stack pointer                             */
  __my_startup,                    /* The reset handler                                 */
  NMI_Handler,                  /*  NMI Handler                                         */
  HardFault_Handler,            /*  Hard Fault Handler                                  */
  MemManage_Handler,            /*  MPU Fault Handler                                   */
  BusFault_Handler,             /*  Bus Fault Handler                                   */
  UsageFault_Handler,           /*  Usage Fault Handler                                 */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  SVC_Handler,                  /*  SVCall Handler                                      */
  DebugMon_Handler,             /*  Debug Monitor Handler                               */
  0,                            /*  Reserved                                            */
  PendSV_Handler,               /*  PendSV Handler                                      */
  SysTick_Handler,              /*  SysTick Handler                                     */

  /* -------------------------------External Exceptions-------------------------------- */
  GPIOPortA_Handler,            /*  GPIO Port A                                         */
  GPIOPortB_Handler,            /*  GPIO Port B                                         */
  GPIOPortC_Handler,            /*  GPIO Port C                                         */
  GPIOPortD_Handler,            /*  GPIO Port D                                         */
  GPIOPortE_Handler,            /*  GPIO Port E                                         */
  UART0_Handler,                /*  UART0 Rx and Tx                                     */
  UART1_Handler,                /*  UART1 Rx and Tx                                     */
  SSI0_Handler,                 /*  SSI0 Rx and Tx                                      */
  I2C0_Handler,                 /*  I2C0 Master and Slave                               */
  PWM0Fault_Handler,            /*  PWM 0 Fault                                         */
  PWM0Generator0_Handler,       /*  PWM 0 Generator 0                                   */
  PWM0Generator1_Handler,       /*  PWM 0 Generator 1                                   */
  PWM0Generator2_Handler,       /*  PWM 0 Generator 2                                   */
  Quadrature0_Handler,          /*  Quadrature Encoder 0                                */
  ADC0Seq0_Handler,             /*  ADC0 Sequence 0                                     */
  ADC0Seq1_Handler,             /*  ADC0 Sequence 1                                     */
  ADC0Seq2_Handler,             /*  ADC0 Sequence 2                                     */
  ADC0Seq3_Handler,             /*  ADC0 Sequence 3                                     */
  WDT_Handler,                  /*  Watchdog                                            */
  Timer0A_Handler,              /*  Timer 0 subtimer A                                  */
  Timer0B_Handler,              /*  Timer 0 subtimer B                                  */
  Timer1A_Handler,              /*  Timer 1 subtimer A                                  */
  Timer1B_Handler,              /*  Timer 1 subtimer B                                  */
  Timer2A_Handler,              /*  Timer 2 subtimer A                                  */
  Timer2B_Handler,              /*  Timer 2 subtimer B                                  */
  Comp0_Handler,                /*  Analog Comp 0                                       */
  Comp1_Handler,                /*  Analog Comp 1                                       */
  Comp2_Handler,                /*  Analog Comp 2                                       */
  SysCtl_Handler,               /*  System Control                                      */
  FlashCtl_Handler,             /*  Flash Control                                       */
  GPIOPortF_Handler,            /*  GPIO Port F                                         */
  GPIOPortG_Handler,            /*  GPIO Port G                                         */
  GPIOPortH_Handler,            /*  GPIO Port H                                         */
  UART2_Handler,                /*  UART2 Rx and Tx                                     */
  SSI1_Handler,                 /*  SSI1 Rx and Tx                                      */
  Timer3A_Handler,              /*  Timer 3 subtimer A                                  */
  Timer3B_Handler,              /*  Timer 3 subtimer B                                  */
  I2C1_Handler,                 /*  I2C1 Master and Slave                               */
  Quadrature1_Handler,          /*  Quadrature Encoder 1                                */
  CAN0_Handler,                 /*  CAN0                                                */
  CAN1_Handler,                 /*  CAN1                                                */
  CAN2_Handler,                 /*  CAN2                                                */
  Ethernet_Handler,             /*  Ethernet                                            */
  Hibernate_Handler,            /*  Hibernate                                           */
  USB0_Handler,                 /*  USB0                                                */
  PWM0Generator3_Handler,       /*  PWM 0 Generator 3                                   */
  uDMA_Handler,                 /*  uDMA Software Transfer                              */
  uDMA_Error,                   /*  uDMA Error                                          */
  ADC1Seq0_Handler,             /*  ADC1 Sequence 0                                     */
  ADC1Seq1_Handler,             /*  ADC1 Sequence 1                                     */
  ADC1Seq2_Handler,             /*  ADC1 Sequence 2                                     */
  ADC1Seq3_Handler,             /*  ADC1 Sequence 3                                     */
  I2S0_Handler,                 /*  I2S0                                                */
  ExtBus_Handler,               /*  External Bus Interface 0                            */
  GPIOPortJ_Handler,            /*  GPIO Port J                                         */
  GPIOPortK_Handler,            /*  GPIO Port K                                         */
  GPIOPortL_Handler,            /*  GPIO Port L                                         */
  SSI2_Handler,                 /*  SSI2 Rx and Tx                                      */
  SSI3_Handler,                 /*  SSI3 Rx and Tx                                      */
  UART3_Handler,                /*  UART3 Rx and Tx                                     */
  UART4_Handler,                /*  UART4 Rx and Tx                                     */
  UART5_Handler,                /*  UART5 Rx and Tx                                     */
  UART6_Handler,                /*  UART6 Rx and Tx                                     */
  UART7_Handler,                /*  UART7 Rx and Tx                                     */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  I2C2_Handler,                 /*  I2C2 Master and Slave                               */
  I2C3_Handler,                 /*  I2C3 Master and Slave                               */
  Timer4A_Handler,              /*  Timer 4 subtimer A                                  */
  Timer4B_Handler,              /*  Timer 4 subtimer B                                  */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  0,                            /*  Reserved                                            */
  Timer5A_Handler,              /*  Timer 5 subtimer A                                  */
  Timer5B_Handler,              /*  Timer 5 subtimer B                                  */
  WideTimer0A_Handler,          /*  Wide Timer 0 subtimer A                             */
  WideTimer0B_Handler,          /*  Wide Timer 0 subtimer B                             */
  WideTimer1A_Handler,          /*  Wide Timer 1 subtimer A                             */
  WideTimer1B_Handler,          /*  Wide Timer 1 subtimer B                             */
  WideTimer2A_Handler,          /*  Wide Timer 2 subtimer A                             */
  WideTimer2B_Handler,          /*  Wide Timer 2 subtimer B                             */
  WideTimer3A_Handler,          /*  Wide Timer 3 subtimer A                             */
  WideTimer3B_Handler,          /*  Wide Timer 3 subtimer B                             */
  WideTimer4A_Handler,          /*  Wide Timer 4 subtimer A                             */
  WideTimer4B_Handler,          /*  Wide Timer 4 subtimer B                             */
  WideTimer5A_Handler,          /*  Wide Timer 5 subtimer A                             */
  WideTimer5B_Handler,          /*  Wide Timer 5 subtimer B                             */
  FPU_Handler,                  /*  FPU                                                 */
  PECI0_Handler,                /*  PECI 0                                              */
  LPC0_Handler,                 /*  LPC 0                                               */
  I2C4_Handler,                 /*  I2C4 Master and Slave                               */
  I2C5_Handler,                 /*  I2C5 Master and Slave                               */
  GPIOPortM_Handler,            /*  GPIO Port M                                         */
  GPIOPortN_Handler,            /*  GPIO Port N                                         */
  Quadrature2_Handler,          /*  Quadrature Encoder 2                                */
  Fan0_Handler,                 /*  Fan 0                                               */
  0,                            /*  Reserved                                            */
  GPIOPortP_Handler,            /*  GPIO Port P (Summary or P0)                         */
  GPIOPortP1_Handler,           /*  GPIO Port P1                                        */
  GPIOPortP2_Handler,           /*  GPIO Port P2                                        */
  GPIOPortP3_Handler,           /*  GPIO Port P3                                        */
  GPIOPortP4_Handler,           /*  GPIO Port P4                                        */
  GPIOPortP5_Handler,           /*  GPIO Port P5                                        */
  GPIOPortP6_Handler,           /*  GPIO Port P6                                        */
  GPIOPortP7_Handler,           /*  GPIO Port P7                                        */
  GPIOPortQ_Handler ,           /*  GPIO Port Q (Summary or Q0)                         */
  GPIOPortQ1_Handler,           /*  GPIO Port Q1                                        */
  GPIOPortQ2_Handler,           /*  GPIO Port Q2                                        */
  GPIOPortQ3_Handler,           /*  GPIO Port Q3                                        */
  GPIOPortQ4_Handler,           /*  GPIO Port Q4                                        */
  GPIOPortQ5_Handler,           /*  GPIO Port Q5                                        */
  GPIOPortQ6_Handler,           /*  GPIO Port Q6                                        */
  GPIOPortQ7_Handler,           /*  GPIO Port Q7                                        */
  GPIOPortR_Handler,            /*  GPIO Port R                                         */
  GPIOPortS_Handler,            /*  GPIO Port S                                         */
  PWM1Generator0_Handler,       /*  PWM 1 Generator 0                                   */
  PWM1Generator1_Handler,       /*  PWM 1 Generator 1                                   */
  PWM1Generator2_Handler,       /*  PWM 1 Generator 2                                   */
  PWM1Generator3_Handler,       /*  PWM 1 Generator 3                                   */
  PWM1Fault_Handler,            /*  PWM 1 Fault                                         */
};
