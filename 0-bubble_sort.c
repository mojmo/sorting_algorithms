#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 * Bubble Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int temp, i = 0, is_swapped = 1;
	size_t j;

	if (array == NULL || size < 2)
		return;

	while (is_swapped)
	{
		is_swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);

				is_swapped = 1;
			}
		}
		i++;
	}

}
