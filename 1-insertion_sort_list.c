#include "sort.h"

/**
 * swapNodes - swaps two nodes of a listint_t
 * @list: the head of the list
 * @a: first node to swapnodes
 * @b: second node to swap
 */
void swapNodes(listint_t **list, listint_t *a, listint_t *b)
{

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	b->prev = a->prev;
	a->next = b->next;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a listint_t using selection sort
 * @list: A pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !(*list)->n)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->prev->n > temp->n)
		{
			swapNodes(list, temp->prev, temp);
			print_list(*list);
		}
		current = current->next;
	}
}
