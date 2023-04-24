#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list using the insertion algorithm.
 * @list: pointer to pointer of a list.
 * Return: Void.
 */


void insertion_sort_list(listint_t **list)
{

	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;

			else
				temp->prev->next = temp;
			print_list(*list);
		}
		current = current->next;
	}
}
