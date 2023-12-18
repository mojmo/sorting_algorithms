#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 * Heap Sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}

}

/**
 * heapify - Recursive function to heapify a subtree rooted
 * at a given index in an array.
 *
 * @array: The array of integers.
 * @size: The total number of elements in the array.
 * @heap_size: The size of the heap or the portion of the array
 *              considered as a heap.
 * @root: The index of the current root node in the heap.
 */
void heapify(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t parent, left, right;

	parent = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < heap_size && array[left] > array[parent])
		parent = left;

	if (right < heap_size && array[right] > array[parent])
		parent = right;

	if (parent != root)
	{
		swap(&array[root], &array[parent]);
		print_array(array, size);
		heapify(array, size, heap_size, parent);
	}
}

/**
 * swap - Swaps the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
