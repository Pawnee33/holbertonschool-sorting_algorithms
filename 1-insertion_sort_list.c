#include "sort.h"

/**
 * swap - Swap two nodes
 * @a: The first node
 * @b: The second node
*/
void swap(listint_t *a, listint_t *b)
{
	listint_t old_a;
	listint_t old_b;

	old_a.prev = a->prev;
	old_a.next = a->next;
	old_b.prev = b->prev;
	old_b.next = b->next;

	if (a->next == b)
	{
		listint_t *x = a->prev;
		listint_t *y = b->next;

		b->prev = x;
		b->next = a;
		a->prev = b;
		a->next = y;
		if (x != NULL)
			x->next = b;
		if (y != NULL)
			y->prev = a;
	}
	else
	{
		a->prev = old_b.prev;
		a->next = old_b.next;
		b->prev = old_a.prev;
		b->next = old_a.next;
		if (old_a.prev != NULL)
			old_a.prev->next = b;
		if (old_a.next != NULL)
		old_a.next->prev = b;
		if (old_b.prev != NULL)
			old_b.prev->next = a;
		if (old_b.next != NULL)
			old_b.next->prev = a;
	}
}

/**
 * insertion_sort_list - Insertion sort algo
 * @list: The list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *root = *list;
	listint_t *last = *list;

	while (last->next)
	{
		listint_t *current = last;
		listint_t *unsorted = last->next;

		while (current && (current->n > unsorted->n))
		{
			swap(current, unsorted);
			current = unsorted->prev;
			if (current == NULL)
				root = unsorted;
			print_list(root);
		}
		if (current == last)
		{
			last = last->next;
		}

	}
	*list = root;
}
