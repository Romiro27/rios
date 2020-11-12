#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>
#include <kernel/vga.h>

void terminal_initialize(void);
void terminal_setcolor(enum vga_color VGACOLOR_F, enum vga_color VGACOLOR_B);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);

#endif
