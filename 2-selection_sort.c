#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, smallest_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_idx])
				smallest_idx = j;
		}

		if (smallest_idx != i)
		{
			temp = array[i];
			array[i] = array[smallest_idx];
			array[smallest_idx] = temp;

			print_array(array, size);
		}
	}
}
