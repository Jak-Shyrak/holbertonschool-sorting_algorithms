#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * @list: List to be sorted
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current;

        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->prev->prev;

            if (temp->prev != NULL)
                temp->prev->next = temp;

            else
                *list = temp;

            temp->next->prev = temp;
            print_list(*list);
        }

        current = current->next;
    }
}