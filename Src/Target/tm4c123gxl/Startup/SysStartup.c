/* ----------------------------------------------------------------------------------- */
// SysStartup.c - Startup code for tm4c123g
//
/* ----------------------------------------------------------------------------------- */
#include <stdint.h>
#include "hw_nvic.h"
#include "hw_types.h"

/* ----------------------------------------------------------------------------------- */
/*  Types defintion                                                                    */
/* ----------------------------------------------------------------------------------- */
typedef void(*function_type)(void);

/* ----------------------------------------------------------------------------------- */
/*  Function prototype                                                                 */
/* ----------------------------------------------------------------------------------- */
void __my_startup() __attribute__((used, noinline));
void crt_init_ram(void);
//void crt_init_ctors(void);
/* ----------------------------------------------------------------------------------- */
/*  Extern data                                                                        */
/* ----------------------------------------------------------------------------------- */
extern uint32_t _etext;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _bss;
extern uint32_t _ebss;

/* ----------------------------------------------------------------------------------- */
/*  Extern functions                                                                   */
/* ----------------------------------------------------------------------------------- */
extern int main(void);

/* ----------------------------------------------------------------------------------- */
/*  Functions implementation                                                           */
/* ----------------------------------------------------------------------------------- */
void __my_startup(void)
{
#if 0
  uint32_t *pui32Src, *pui32Dest;

  //
  // Copy the data segment initializers from flash to SRAM.
  //
  pui32Src = &_etext;
  for(pui32Dest = &_data; pui32Dest < &_edata; )
  {
      *pui32Dest++ = *pui32Src++;
  }

  //
  // Zero fill the bss segment.
  //
  __asm("    ldr     r0, =_bss\n"
        "    ldr     r1, =_ebss\n"
        "    mov     r2, #0\n"
        "    .thumb_func\n"
        "zero_loop:\n"
        "        cmp     r0, r1\n"
        "        it      lt\n"
        "        strlt   r2, [r0], #4\n"
        "        blt     zero_loop");

    // TBD do this with register set
    // Enable the floating-point unit.  This must be done here to handle the
    // case where main() uses floating-point and the function prologue saves
    // floating-point registers (which will fault if floating-point is not
    // enabled).  Any configuration of the floating-point unit using DriverLib
    // APIs must be done here prior to the floating-point unit being enabled.
    //
    // Note that this does not use DriverLib since it might not be included in
    // this project.
    HWREG(NVIC_CPAC) = ((HWREG(NVIC_CPAC) &
                         ~(NVIC_CPAC_CP10_M | NVIC_CPAC_CP11_M)) |
                        NVIC_CPAC_CP10_FULL | NVIC_CPAC_CP11_FULL);

    //
    // Call the application's entry point.
    //
    main();
#endif

  /* Load the stack pointer.                          */
  /* The stack pointer is automatically loaded from   */
  /* the base position of the interrupt vector table  */
  /* So we do nothing here.                           */

  /* Initialize statics from ROM to RAM               */
  /* Zero-clear default-initialized static RAM        */
  crt_init_ram();

  /* Call all ctor initializations                    */
  //crt_init_ctors();

  /* Jump to main (and never return)                  */
  (void) main();

  /* Catch an unexpected return from main.            */
  for(;;)
  {
    /* Replace with a loud error if desired.          */
  }

}

void crt_init_ram(void)
{
  /* Copy the data segment initializers from ROM to RAM.*/
  /* Note that all data segments are aligned by 4.      */
  const unsigned size_data = (unsigned) ((uint8_t*) (&_edata) - (uint8_t*) &_data);

  for(unsigned i = 0U; i < size_data; ++i)
  {
    ((uint8_t*) &_data)[i] = ((const uint8_t*) &_etext)[i];
  }

  const unsigned size_bss = (unsigned) ((uint8_t*) (&_ebss) - (uint8_t*) &_bss);

  /* Clear the bss segment.*/
  for(unsigned i = 0U; i < size_bss; ++i)
  {
    ((uint8_t*) &_bss)[i] = (uint8_t) 0U;
  }
}

//void crt_init_ctors(void)
//{
//  for(function_type* pfn = (function_type*) &_ctors_begin; pfn != (function_type*) &_ctors_end; ++pfn)
//  {
//    (*pfn)();
//  }
//}

