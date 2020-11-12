#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _div_t
{
	int quot;
	int rem;
} div_t;

__attribute__((__noreturn__))
void abort(char error[256]);
div_t div(int numer, int denom);

#ifdef __cplusplus
}
#endif

#endif
