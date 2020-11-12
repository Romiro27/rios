/**
 * @author      : romiro27 (vanno6521@gmail.com)
 * @file        : comb.h
 * @created     : Sunday Sep 13, 2020 14:02:20 +04
 */

#ifndef COMB_H
#define COMB_H

#include <vector>

void combSort(std::vector<int> &data)
{
    double factor = 1.2473309;
    double step = data.size() - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < data.size(); i++)
        {
            if (data[i] > data[i + step])
            {
                std::swap(data[i], data[i + step]);
            }
        }
        step /= factor;
    }

    for (int i = 0; i < data.size() - 1; i++)
    {
        for (int j = 0; j < data.size() - i; j--)
        {
            std::swap(data[j], data[j + 1]);
        }
    }


}

#endif

