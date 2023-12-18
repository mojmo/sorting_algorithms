#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **head, listint_t **f_node, listint_t *s_node);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int start, int end, size_t size);
void perform_quicksort(int *array, int start, int end, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes_forward(listint_t **head, listint_t **tail, listint_t **curr);
void swap_nodes_backward(listint_t **head, listint_t **tail, listint_t **curr);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void perform_merge(int *new_arr, size_t start_i, size_t end_i, int *arr);
void merge(int *new_arr, size_t start_i, size_t mid_i, size_t end_i, int *arr);
void copy_array(int *arr, size_t start_i, size_t end_i, int *new_arr);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t heap_size, size_t root);
void swap(int *a, int *b);

#endif /* SORT_H */
