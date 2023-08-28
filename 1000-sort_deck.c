#include "deck.h"
#include <stdio.h>
int get_value(const char *str);
void swap(deck_node_t *curr, deck_node_t *sorted);
void insertion_sort_kind(deck_node_t **list);
void insertion_sort_card(deck_node_t **list, int value);
/**
 * sort_deck - sorts a deck of cards
 * @deck: double pointer
 * Return: nothing
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_kind(deck);
	insertion_sort_card(deck, 0);

}
/**
 * insertion_sort_card - sorts a doubly linked list of
 * integers in ascending order
 * @list: double pointer
 * @value: card value
 * Return: nothing
 */

void insertion_sort_card(deck_node_t **list, int value)
{
	deck_node_t *curr, *temp, *sorted;
	int i, j;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	curr = *list;
	while (curr != NULL)
	{
		if ((int)curr->card->kind != value)
			value++;
		temp = curr->next;
		sorted = curr->prev;
		while (sorted != NULL && curr->card->kind == sorted->card->kind)
		{
			i = get_value(curr->card->value);
			j = get_value(sorted->card->value);
			if (i >= j)
				break;
			/*insert curr before sorted*/
			swap(curr, sorted);
			if (curr->prev == NULL)
				*list = curr;
			sorted = curr->prev;
		}
		curr = temp;
	}
}
/**
 * insertion_sort_kind - sorts a doubly linked list of
 * integers in ascending order
 * @list: double pointer
 * Return: nothing
 */

void insertion_sort_kind(deck_node_t **list)
{
	deck_node_t *curr, *temp, *sorted;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	curr = *list;
	while (curr != NULL)
	{
		temp = curr->next;
		sorted = curr->prev;
		while (sorted != NULL)
		{
			if (curr->card->kind >= sorted->card->kind)
				break;
			/*insert curr before sorted*/
			swap(curr, sorted);
			if (curr->prev == NULL)
				*list = curr;
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
void swap(deck_node_t *curr, deck_node_t *sorted)
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
	deck_node_t *temp;

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
/**
 * get_value - gets value of the card
 * @str: card name
 * Return: card value
 */
int get_value(const char *str)
{
	int i = 0;
	value_t array[] = {
		{"Ace", 1},
		{"2", 2},
		{"3", 3},
		{"4", 4},
		{"5", 5},
		{"6", 6},
		{"7", 7},
		{"8", 8},
		{"9", 9},
		{"10", 10},
		{"Jack", 11},
		{"Queen", 12},
		{"King", 13},
		{NULL, -1}
	};
	while (array[i].value != NULL)
	{
		if (strcmp(str, array[i].value) == 0)
		{
			return (array[i].n);
		}
		i++;
	}
	return (-1);
}
