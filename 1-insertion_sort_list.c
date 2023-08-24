#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: double pointer
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *sorted, *ptr;


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
			sorted = curr;
		}
		else
		{
			ptr = sorted;
			while (ptr->next != NULL && ptr->next->n < curr->n)
			{
				ptr = ptr->next;
			}
			curr->next = ptr->next;
			ptr->next = curr;
		}
		print_list(sorted);
		curr = temp;
	}
	*list = sorted;
}
