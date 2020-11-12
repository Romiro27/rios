#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <arch/i386/idt.h>
#include <kernel/tty.h>
//#include <rilib/random.h>
//#include <kernel/idt.h>

//extern void shutdown();
void kerr(char error[256]);

void kernel_main(void)
{
	idt_init();
	terminal_writestring("IDT initialized\n");

	/* Initialize terminal interface */
	terminal_initialize();
	terminal_writestring("Terminal initialized\n");
	printf("====================\n");
	printf("=       ======    ==\n");
	printf("=  ====  ======  ===\n");
	printf("=  ===  =======  ===\n");
	printf("=      ========  ===\n");
	printf("=  ====  ======  ===\n");
	printf("=  ====  =====    ==\n");
	printf("====================\n");
	terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_RED);
	terminal_writestring("RI System was been started!\n\n");
	terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

	// terminal_setcolor(VGA_COLOR_LIGHT_BLUE, VGA_COLOR_BLACK);
	// printf("L");
	// terminal_setcolor(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
	// printf("M");
	// terminal_setcolor(VGA_COLOR_LIGHT_CYAN, VGA_COLOR_BLACK);
	// printf("A");
	// terminal_setcolor(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
	// printf("O");
	// terminal_setcolor(VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_BLACK);
	// printf("!\n");
	// terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

	printf("Hello, today a nice day!\n\n");

	/* NOT WORKING! */
		//int data = random(0);
		//int data = 123;
		//char* t_data;
		//itoa(data, t_data, 10);
		//printf(t_data + '\n');
	/* NOT WORKING! */

	// printf("    ___   _____ ______________     ___    ____  ______\n");
	// printf("   /   | / ___// ____/  _/  _/    /   |  / __ \\/_  __/\n");
	// printf("  / /| | \\__ \\/ /    / / / /     / /| | / /_/ / / /   \n");
	// printf(" / ___ |___/ / /____/ /_/ /     / ___ |/ _, _/ / /    \n");
	// printf("/_/  |_/____/\\____/___/___/    /_/  |_/_/ |_| /_/     \n\n");

	// terminal_setcolor(VGA_COLOR_BLACK, VGA_COLOR_LIGHT_GREY);
	// printf("d8888b. db    db .d8888. .d8888. d888888b  .d8b.  \n");
	// printf("88  `8D 88    88 88'  YP 88'  YP   `88'   d8' `8b \n");
	// terminal_setcolor(VGA_COLOR_BLACK, VGA_COLOR_BLUE);
	// printf("88oobY' 88    88 `8bo.   `8bo.      88    88ooo88 \n");
	// printf("88`8b   88    88   `Y8b.   `Y8b.    88    88~~~88 \n");
	// terminal_setcolor(VGA_COLOR_BLACK, VGA_COLOR_RED);
	// printf("88 `88. 88b  d88 db   8D db   8D   .88.   88   88 \n");
	// printf("88   YD ~Y8888P' `8888Y' `8888Y' Y888888P YP   YP ");
	// terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

	//kerr("test kerr");

	unsigned int a = 101;
	unsigned int b = 0x00000F;
	char* buff;
	char* hex_buff;

	itoa(a, buff, 10);

	printf("%u\n", a);
	printf("%s\n", buff);

	itoa(b, hex_buff, 16);

	printf("%x\n", b);
	printf("%s\n", hex_buff);
}

// void GDTentry(uint8_t *target, struct GDT source)
// {
// 	if()
// 	{

// 	}
// }