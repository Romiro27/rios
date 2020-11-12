/**
 * @author      : romiro27 (vanno6521@gmail.com)
 * @file        : insertion.h
 * @created     : Sunday Sep 13, 2020 18:48:30 +04
 */

#ifndef INSERTION_H
#define INSERTION_H

void insertionSort(std::vector<int> &data)
{
    int len = data.size();

    for (int i = 1; i < len; i++)
    {
        int temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}

#endif

