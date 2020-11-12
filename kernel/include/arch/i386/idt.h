/**
 * @author      : romiro27 (vanno6521@gmail.com)
 * @file        : idt.h
 * @created     : Wednesday Nov 11, 2020 22:06:39 +04
 */

#ifndef IDT_H
#define IDT_H

#include <stdint.h>

struct IDT_entry
{
    uint16_t offset_lowerbits;
    uint16_t selector;
    uint8_t  zero;
    uint8_t  type_attr;
    uint16_t offset_higherbits;
};

void idt_init();
IDT_entry *get_itd(); // COMPILING ERROR
// https://github.com/ulmer-a/ulmix-i686/blob/master/arch/include/asm.h
// https://github.com/ulmer-a/ulmix-i686/blob/master/arch/i686/idt.c

#endif

