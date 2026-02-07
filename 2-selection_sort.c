#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: the array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int min, flag;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		index = i;
		flag = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
				flag = 1;
			}
		}

		array[index] = array[i];
		array[i] = min;

		if (flag)
			print_array(array, size);
	}
}
