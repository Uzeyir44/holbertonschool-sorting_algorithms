#include sort.h
#include <stdio.h>

void bubble_sort(int *array, size_t size)
{
    int swap;
    int flag;

    for (size_t i = 0; i < size - 1; i++) 
    {
        flag = 0;

        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j+1])
            {
                swap = array[j+1];
                array[j+1] = array[j];
                array[j] = swap;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}