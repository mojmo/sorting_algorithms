#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 * Shell Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Initialize gap as the largest power of 3 less than size */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap /= 3)
	{
		/* Perform insertion sort for the current gap */
		for (i = gap; i < size; i++)
		{
			j = i;
			while ((j >= gap) && (array[j - gap] > array[j]))
			{
				temp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = temp;

				j -= gap;
			}
		}
		print_array(array, size);
	}
}
