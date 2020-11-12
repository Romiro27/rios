/**
 * @author      : romiro27 (vanno6521@gmail.com)
 * @file        : shaker.h
 * @created     : Sunday Sep 13, 2020 12:28:34 +04
 */

#ifndef SHAKER_H
#define SHAKER_H

#include <vector>

inline void shakerSort(std::vector<int> &data)
{
    if (data.size() <= 0) return;

    bool moved = false;
    int buff = 0;
    int left = 0;
    int right = data.size() - 1;

    do 
    {
        moved = false;
        for (int i = left; i < right; i++)
        {
            if (data[i + 1] < data[i])
            {
                buff = data[i];
                // asm volatile(
                //     "movl %[dataI], %[buff]\n\t"
                //     :[buff]"=r"(buff)
                //     :[dataI]"m"(data[i])
                //     :"cc"
                //     ); 

                data[i] = data[i + 1];
                // asm volatile(
                //     "movl %[dataI1], %[dataI]\n\t"
                //     :[dataI]"=r"(data[i])
                //     :[dataI1]"m"(data[i+1])
                //     :"cc"
                //     );

                data[i + 1] = buff;
                // asm volatile(
                //     "movl %[buff], %[dataI1]\n\t"
                //     :[dataI1]"=r"(data[i+1])
                //     :[buff]"m"(buff)
                //     :"cc"
                //     );

                moved = true;
            }
        }
        right--;

        for (int i = right; i > left; i--)
        {
            if (data[i - 1] > data[i])
            {

                buff = data[i];
                // asm volatile(
                //     "movl %[dataI], %[buff]\n\t"
                //     :[buff]"=r"(buff)
                //     :[dataI]"m"(data[i])
                //     :"cc"
                //     );

                data[i] = data[i - 1];
                // asm volatile(
                //     "movl %[dataI1], %[dataI]\n\t"
                //     :[dataI]"=r"(data[i])
                //     :[dataI1]"m"(data[i-1])
                //     :"cc"
                //     );

                data[i - 1] = buff;
                // asm volatile(
                //     "movl %[buff], %[dataI1]\n\t"
                //     :[dataI1]"=r"(data[i-1])
                //     :[buff]"m"(buff)
                //     :"cc"
                //     );

                moved = true;
            }
        }
        left++;
    } while (moved);
}

#endif

