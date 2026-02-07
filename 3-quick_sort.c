#include "sort.h"

void patiticm(size_t l, size_t h, int *array)
{
    int pivot = array[(h-l) / 2];
    size_t i = l; 
    size_t j = h;
    int holder;

    if (i >= j)
        return;

    while (i < j)
    {
        while (array[i] < pivot)
        {
            i++;
        }
        while (array[j] >= pivot)
        {
            j--;
        }

        holder = array[i];
        array[i] = array[j];
        array[j] = holder;
    }

    array[(h-l) / 2] = array[j];
    array[j] = pivot;

    patiticm(l, j, array);
    patiticm(j+1, h, array);
}

void quick_sort(int *array, size_t size)
{
    patiticm(0, size - 1, array);
}