/*
******************************************************************************
**
** Copyright Iliass Mahjoub 2023 - 2024.
**
** Distributed under the Boost Software License,
** Version 1.0. (See accompanying file LICENSE_1_0.txt
** or copy at http://www.boost.org/LICENSE_1_0.txt)
**
******************************************************************************
*/

/* Entry Point */
ENTRY(__my_startup)

/* Highest address of the user mode stack */
__initial_stack_pointer = ORIGIN(SRAM) + LENGTH(SRAM); /* end of "FLASH" Ram type memory */

MEMORY
{
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00040000
}

SECTIONS
{
    .text :
    {
        _text = .;
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        _etext = .;
    } > FLASH

    .data : AT(ADDR(.text) + SIZEOF(.text))
    {
        _data = .;
        *(vtable)
        *(.data*)
        _edata = .;
    } > SRAM

    .bss :
    {
        _bss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > SRAM
}
