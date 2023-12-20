#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers using Radix Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The number of elements in the array.
 *
 * This function sorts the elements of an integer array in ascending order
 * using the Radix Sort algorithm with the LSD (Least Significant Digit)
 * variant. It performs multiple passes through the array, each time sorting
 * the elements based on a specific digit place, starting from the units
 * place and progressing towards the most significant digit.
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	/* Apply counting sort to sort elements based on place value. */
	for (place = 1; max / place > 0; place *= 10)
	{
		counting_sort_LSD(array, size, place);
		print_array(array, size);
	}
}

/**
 * counting_sort_LSD - Performs counting sort on a specified digit place.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The number of elements in the array.
 * @place: The current digit place (e.g., units, tens).
 *
 * This function performs counting sort on the given array based on the
 * specified digit place (e.g., units, tens). It assumes that the values
 * are non-negative integers and within a reasonable range. The sorted
 * result is updated in the original array.
 */
void counting_sort_LSD(int *array, size_t size, int place)
{
	int *count, *output;
	int range;
	size_t i;

	range = 10;
	output = malloc(size * sizeof(int));
	if (!output)
		return;

	count = malloc(range * sizeof(int));
	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i < (size_t)range; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	/* Calculate cumulative count */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

/**
 * get_max - Finds the maximum value in an array.
 *
 * @array: Pointer to the array to find the maximum value.
 * @size: The number of elements in the array.
 *
 * Return: The maximum value in the array.
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}
