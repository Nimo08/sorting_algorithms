#include "sort.h"
void swap(listint_t *curr, listint_t *sorted);
/**
 * cocktail_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: double pointer
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *sorted;
	int flag = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	while (flag)
	{
		flag = 0;
		curr = *list;
		/*3, 1, 2*/

		while (curr != NULL && curr->next != NULL)
		{
			if (curr->n > curr->next->n)
			{
				sorted = curr->next;
				swap(curr->next, curr);
				if (sorted->prev == NULL)
					*list = sorted;
				print_list(*list);
				flag = 1;
				curr = curr->prev;
			}
			if (curr != NULL)
				curr = curr->next;
		}
		if (flag == 0)
			break;
		curr = curr->prev;
		while (curr != NULL && curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				swap(curr, curr->prev);
				if (curr->prev == NULL)
					*list = curr;
				print_list(*list);
				flag = 1;
				curr = curr->next;
			}
			if (curr != NULL)
				curr = curr->prev;
		}
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
