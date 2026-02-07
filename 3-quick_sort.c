#include "sort.h"

void patiticm(size_t l, size_t h, int *array)
{
    int pivot;
    int holder;
    size_t i = l;
    size_t j = h - 1;

    if (l >= h)
        return;

    pivot = array[h];

    while (i < j)
    {
        while (array[i] < pivot)
        {
            i++;
            if (i > j)
                break;
        }
        while (array[j] >= pivot)
        {
            j--;
            if (i > j)
                break;
        }
        if (i < j)
        {
            holder = array[i];
            array[i] = array[j];
            array[j] = holder;
        }
    }

    array[h] = array[i];
    array[i] = pivot;
    if (i > l)
        patiticm(l, i-1, array);
    patiticm(i+1, h, array);
}

void quick_sort(int *array, size_t size)
{
    if (array != NULL && size > 1)
        patiticm(0, size - 1, array);
}