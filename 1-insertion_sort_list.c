#include "sort.h"

/**
 * insertion_sort_list - trie une liste doublempent chainée d'entiers
 * @list: liste à trier
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *head, *previous, *prev_inner, *current_inner;

	if (list == NULL)
		return;
	if ((*list) == NULL || (*list)->next == NULL)
		return;
	previous = *list;
	current = (*list)->next;
	head = *list;
	while (current)
	{
		current_inner = current;
		prev_inner = previous;
		while (prev_inner && prev_inner->n > current_inner->n)
		{
			if (prev_inner->prev == NULL)
				head = current_inner;
			if (current_inner == current)
				current = prev_inner;
			if (current_inner->next != NULL)
				current_inner->next->prev = prev_inner;
			if (prev_inner->prev != NULL)
				prev_inner->prev->next = current_inner;
			current_inner->prev = prev_inner->prev;
			prev_inner->next = current_inner->next;
			current_inner->next = prev_inner;
			prev_inner->prev = current_inner;
			prev_inner = current_inner->prev;
			print_list(head);
		}
		previous = current;
		current = current->next;
	}
	*list = head;
}
