/**
 * @author      : romiro27 (vanno6521@gmail.com)
 * @file        : bubble.h
 * @created     : Friday Sep 11, 2020 00:41:53 +04
 */

#ifndef BUBBLE_H
#define BUBBLE_H

inline void bubbleSort (std::vector<int> &data)
{
	if (data.size() <= 0) return;

	const unsigned int len = data.size();

	for (unsigned int i = len - 1; i--;)
	{
		for (unsigned int j = len - i; j--;)
		{
			if (data[j] > data[j + 1])
			{                
				int tmp = data[j];
/*                asm volatile(
				   "movl %[dataJ], %%eax\n\t"
				   :"=a"(tmp)
				   :[dataJ]"m"(data[j])
				   );*/

				data[j] = data[j + 1];
/*                asm volatile(
					"movl %[dataJ1], %%ebx\n\t"
					:"=b"(data[j])
					:[dataJ1]"m"(data[j+1])
					);
*/
				data[j + 1] = tmp;
/*                asm volatile(
					"movl %[tmp], %%ecx\n\t"
					:"=c"(data[j+1])
					:[tmp]"m"(tmp)
					);*/
			}
		}
	}
}

#endif

