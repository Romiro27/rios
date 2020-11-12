#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>
#include <kernel/vga.h>
//#include "idt.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This source will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This source needs to be compiled with a ix86-elf compiler"
#endif

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

static inline size_t vga_index(size_t x, size_t y) 
{
	return y * VGA_WIDTH + x;
}

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;


/* TTY LEGACY CODE */

void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) 
	{
		for (size_t x = 0; x < VGA_WIDTH; x++) 
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(enum vga_color VGACOLOR_F, enum vga_color VGACOLOR_B) 
{
	uint8_t color = vga_entry_color(VGACOLOR_F, VGACOLOR_B);
 	terminal_color = color;
}

void terminal_scroll()
{
	size_t x, y;
	for(y = 0; y < VGA_HEIGHT - 1; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			terminal_buffer[vga_index(x,y)] = terminal_buffer[vga_index(x,y+1)];
		}
	}
	for (x = 0; x < VGA_WIDTH; x++) {
		terminal_buffer[vga_index(x,y)] = vga_entry(' ', terminal_color);
	}
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) 
{
	if (c == '\n')
	{
		terminal_column = 0;
		++terminal_row;
		if (terminal_row == VGA_HEIGHT)
		{
			--terminal_row;
			terminal_scroll();
		}
		return;
	}

	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);

	if (++terminal_column == VGA_WIDTH)
	{
		terminal_column = 0;

		if (++terminal_row == VGA_HEIGHT)
		{
			//terminal_row = 0;
			terminal_scroll();
		}
	}
}

void terminal_write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
	{
		terminal_putchar(data[i]);
	}
}
 
void terminal_writestring(const char* data) 
{
	terminal_write(data, strlen(data));
}

/* TTY LEGACY CODE */