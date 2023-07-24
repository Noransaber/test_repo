#include "sort.h"
/**
 * move_left - swap between two nodes
 * @sec: second node to be swapped
 * @first: first node
 * @h: head
 **/
void move_left(listint_t *sec, listint_t *first, listint_t **h)
{
	listint_t *s1 = sec->next;
	listint_t *s2 = first->prev;

	if (s1 != NULL)
		s1->prev = first;
	if (s2 != NULL)
		s2->next = sec;

	sec->prev = s2;
	first->next = s1;

	sec->next = first;
	first->prev = sec;

	if (*h == first)
	{
		*h = sec;
	}
	print_list(*h);
}
/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order
 * @list: the list to be sorted
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *min = NULL;
	listint_t *max = NULL;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	curr = *list;
	do {
		while (curr->next)
		{
			if (curr->n > curr->next->n)
				move_left(curr->next, curr, list);
			else
				curr = curr->next;
		}

		max = curr;

		while (curr->prev != min)
		{
			if (curr->n < curr->prev->n)
				move_left(curr, curr->prev, list);
			else
				curr = curr->prev;
		}
		min = curr;
	}
		while (min != max);
}
