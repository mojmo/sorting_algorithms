#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion Sort algorithm.
 *
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (!list || !*list || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		previous = current->prev;
		while (previous != NULL && previous->n > current->n)
		{
			swap_nodes(list, &previous, current);
			print_list((const listint_t *) *list);
		}
		current = current->next;
	}

}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @head: Double pointer to the head of the doubly linked list.
 * @f_node: Double pointer to the first node to be swapped.
 * @s_node: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **head, listint_t **f_node, listint_t *s_node)
{
	(*f_node)->next = s_node->next;

	if (s_node->next != NULL)
		s_node->next->prev = *f_node;

	s_node->prev = (*f_node)->prev;
	s_node->next = *f_node;

	if ((*f_node)->prev != NULL)
		(*f_node)->prev->next = s_node;
	else
		*head = s_node;

	(*f_node)->prev = s_node;
	*f_node = s_node->prev;
}
