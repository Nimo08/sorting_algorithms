#include "sort.h"
void swap(listint_t *curr, listint_t *sorted);
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
		while (sorted != NULL)
		{
				if (curr->n >= sorted->n)
					break;
				/*insert curr before sorted*/
				swap(curr, sorted);
				if (curr->prev == NULL)
					*list = curr;
				print_list(*list);
				sorted = curr->prev;
		}
		curr = temp;
	}
}
/**
 * swap - swaps the nodes
 * @curr:  current node
 * @sorted: sorted node
 * Return: nothing
 */
void swap(listint_t *curr, listint_t *sorted)
{
	/**
	 * insert curr before sorted
	 * account for curr->prev, curr->next
	 * sorted->prev, sorted->next
	 * curr->next = sorted, sorted->prev = curr
	 * curr->prev is going to be the original sorted->prev
	 * curr->next is going to be original sorted
	 * 7, 8, 2, 4
	 * temp stores the 4, so curr->next = 4
	 * sorted->next = temp
	 * curr->prev = sorted->prev
	 * temp->prev = curr
	 */
	listint_t *temp;

	temp = curr->next;
	curr->next = sorted;
	curr->prev = sorted->prev;
	if (sorted->prev != NULL)
	{
		sorted->prev->next = curr;
	}
	sorted->prev = curr;
	sorted->next = temp;
	if (temp != NULL)
	{
		temp->prev = sorted;
	}
}
