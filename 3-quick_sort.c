#include "sort.h"

/**
 * patiticm - partitions an array using Lomuto scheme
 * @l: left index
 * @h: right index
 * @array: array to sort
 * @size: size of array for printing
 */
void patiticm(size_t l, size_t h, int *array, size_t size)
{
	size_t i, j;
	int pivot, holder;

	if (l >= h)
		return;

	pivot = array[h];
	i = l;

	for (j = l; j < h; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				holder = array[i];
				array[i] = array[j];
				array[j] = holder;
				print_array(array, size);
			}
			i++;
		}
	}

	/* final pivot swap, only if needed */
	if (i != h)
	{
		holder = array[i];
		array[i] = array[h];
		array[h] = holder;
		print_array(array, size);
	}

	if (i > l)
		patiticm(l, i - 1, array, size);
	if (i < h)
		patiticm(i + 1, h, array, size);
}

/**
 * quick_sort - sorts an array of integers using quicksort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		patiticm(0, size - 1, array, size);
}
