#include "sort.h"

/**
 * patiticm - partitions an array and sorts recursively
 * @l: left index
 * @h: right index
 * @array: array to sort
 */
void patiticm(size_t l, size_t h, int *array)
{
	size_t i, j;
	int pivot, holder;

	if (l >= h)
		return;

	pivot = array[h];
	i = l;
	j = h - 1;

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
			if (j == 0)
				break;
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

	holder = array[i];
	array[i] = array[h];
	array[h] = holder;

	if (i > l)
		patiticm(l, i - 1, array);
	if (i < h)
		patiticm(i + 1, h, array);
}

/**
 * quick_sort - sorts an array of integers using quicksort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		patiticm(0, size - 1, array);
}
