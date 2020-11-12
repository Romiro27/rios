#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(char error[256]) {
#if defined(__is_libk)
	// TODO: Add proper kernel panic.
	printf("kernel: error: %s\n", error);
#else
	// TODO: Abnormally terminate the process as if by SIGABRT.
	printf("abort()\n");
#endif
	while (1) { }
	__builtin_unreachable();
}
