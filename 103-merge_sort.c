#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge_sort - Sorts an array of integers using the
 * Merge Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *new_arr;

	if (array == NULL || size < 2)
		return;

	new_arr = malloc(sizeof(int) * size);
	if (!new_arr)
		return;

	copy_array(array, 0, size, new_arr);
	perform_merge(new_arr, 0, size, array);

	free(new_arr);
}

/**
 * perform_merge - Recursively divides and merges the array.
 *
 * @new_arr: The auxiliary array for merging.
 * @start_i: The starting index of the subarray.
 * @end_i: The ending index of the subarray.
 * @arr: The original array to be sorted.
 */
void perform_merge(int *new_arr, size_t start_i, size_t end_i, int *arr)
{
	size_t mid_i;

	if (end_i - start_i > 1)
	{
		mid_i = start_i + (end_i - start_i) / 2;

		perform_merge(arr, start_i, mid_i, new_arr);
		perform_merge(arr, mid_i, end_i, new_arr);
		merge(new_arr, start_i, mid_i, end_i, arr);
	}
}

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 *
 * @new_arr: The auxiliary array for merging.
 * @start_i: The starting index of the first subarray.
 * @mid_i: The ending index of the first subarray (exclusive) and starting
 *         index of the second subarray.
 * @end_i: The ending index of the second subarray.
 * @arr: The original array to be sorted.
 */
void merge(int *new_arr, size_t start_i, size_t mid_i, size_t end_i, int *arr)
{
	size_t i = start_i, j = mid_i, k;

	printf("Merging...\n[left]: ");
	print_array(new_arr + start_i, mid_i - start_i);
	printf("[right]: ");
	print_array(new_arr + mid_i, end_i - mid_i);

	for (k = start_i; k < end_i; k++)
	{
		if (i < mid_i && (j >= end_i || arr[i] <= arr[j]))
		{
			new_arr[k] = arr[i];
			i = i + 1;
		}
		else
		{
			new_arr[k] = arr[j];
			j = j + 1;
		}
	}

	copy_array(new_arr, 0, end_i, arr);

	printf("[Done]: ");
	print_array(new_arr + start_i, end_i - start_i);
}

/**
 * copy_array - Copies elements from one array to another.
 *
 * @arr: The source array.
 * @start_i: The starting index in the source array.
 * @end_i: The ending index (exclusive) in the source array.
 * @new_arr: The destination array.
 */
void copy_array(int *arr, size_t start_i, size_t end_i, int *new_arr)
{
	size_t j;

	for (j = start_i; j < end_i; j++)
		new_arr[j] = arr[j];
}
