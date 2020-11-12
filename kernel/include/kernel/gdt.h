/**
 * @author      : romiro27 (vanno6521@gmail.com)
 * @file        : gdt.h
 * @created     : Wednesday Nov 11, 2020 22:44:53 +04
 */

#ifndef GDT_H
#define GDT_H

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

void create_descriptor(uint32_t base, uint32_t limit, uint16_t flag);
void init_gdt();

#endif

