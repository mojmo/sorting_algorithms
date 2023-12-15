#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the QuickSort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int start, end;

	if (array == NULL || size < 2)
		return;

	start = 0;
	end = size - 1;

	perform_quicksort(array, start, end, size);
}

/**
 * perform_quicksort - Recursively performs the QuickSort algorithm
 * on subarrays.
 *
 * @array: Pointer to the array to be sorted.
 * @start: Starting index of the current subarray.
 * @end: Ending index of the current subarray.
 * @size: Size of the array.
 */
void perform_quicksort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		perform_quicksort(array, start, pivot - 1, size);
		perform_quicksort(array, pivot + 1, end, size);
	}
}

/**
 * partition - Partitions an array and places the pivot in its sorted position.
 *
 * @array: Pointer to the array to be partitioned.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * @size: Size of the array.
 *
 * Return: Index of the pivot after partitioning.
 */
int partition(int *array, int start, int end, size_t size)
{
	int i = start, j, temp;

	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
		{
			if (i < j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			i++;
		}
	}


	if (array[i] > array[end])
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (i);
}
