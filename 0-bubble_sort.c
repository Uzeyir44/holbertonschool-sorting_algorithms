#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers using Bubble sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int swap;
	int flag;
	size_t i;
	size_t j;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j + 1];
				array[j + 1] = array[j];
				array[j] = swap;
				flag = 1;

				print_array(array, size);
			}
		}

		if (flag == 0)
			break;
	}
}
