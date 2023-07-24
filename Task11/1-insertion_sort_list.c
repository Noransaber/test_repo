#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: the list to be sorted
 * Return: Nothing
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *first = NULL;
	listint_t *sec = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sec = (*list)->next;
	first = sec->prev;

	while (sec != NULL)
	{
		first = sec->prev;
		while (first != NULL && first->n > sec->n)
		{
			linklist_swapping(sec, first, list);
			first = sec->prev;
		}
		sec = sec->next;
	}
}

/**
 * linklist_swapping - swap between two nodes
 * @sec: second node to be swapped
 * @first: first node
 * @h: head
 **/
void linklist_swapping(listint_t *sec, listint_t *first, listint_t **h)
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
		*h = sec;
	print_list(*h);
}
