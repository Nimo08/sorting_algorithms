#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: double pointer
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *sorted;


	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}
	sorted = NULL;
	curr = *list;
	while (curr != NULL)
	{
		temp = curr->next;
		if (sorted == NULL || curr->n < sorted->n)
		{
			curr->next = sorted;
			curr->prev = NULL;
			if (sorted != NULL)
			{
				curr->prev = sorted->prev;
				sorted->prev = curr;
			}
			sorted = curr;
			while (sorted != NULL && curr->n < sorted->n)
			{
				if (curr->n > sorted->n)
					break;
				curr->next = sorted->next
				sorted = sorted->prev;
			}
		}
		print_list(sorted);
		curr = temp;
	}
	*list = sorted;
}
