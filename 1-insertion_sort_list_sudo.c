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
		sorted = curr->prev;
		if (sorted == NULL || curr->n < sorted->n)
		{
			if (sorted != NULL)
			{
				/*insert curr before sorted*/	
			}
			sorted = curr;
			if (curr->prev == NULL)
				*list = curr;
			print_list(*list);
			while (sorted != NULL)
			{
				if (curr->n >= sorted->n)
					break;
				/*insert curr before sorted*/
				if (curr->prev == NULL)
					*list = curr;
				print_list(*list);
				sorted = sorted->prev;
			}
		}
		curr = temp;
	}
}
