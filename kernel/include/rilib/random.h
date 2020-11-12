/**
 * @author      : romiro27 (vanno6521@gmail.com)
 * @file        : random.h
 * @created     : Friday Sep 18, 2020 20:14:06 +04
 */

#ifndef RANDOM_H
#define RANDOM_H

typedef unsigned long long ull;

inline ull rdtsc() {
	unsigned int lo, hi;
	asm volatile ( "rdtsc\n" : "=a" (lo), "=d" (hi) );
	return ((ull)hi << 32) | lo;
}

int random (int data)
{
	int temp = rdtsc();

    asm volatile(
	   "movl %%eax, %[data]\n\t"
	   :"=a"(data)
	   :[data]"m"(data)
	   );

    data = (data * temp);

    if (data < 0)
    	return data * -1;
    else
    	return data;
}

#endif