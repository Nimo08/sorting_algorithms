#include "sort.h"
/**
 * partition - Entry point
 * Description: quick sort starting point
 * @array: array to sort
 * @s: first index of the partition
 * @e: last index of the partition
 * @size: size of the entire array
 * Return: index of the pivot
 */
int partition(int *array, int s, int e, size_t size)
{
	int pivot = array[e], temp;
	int i = s - 1; /*last smaller idx*/
	int j = e + 1; /*last bigger idx*/;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	return (i);
}
/**
 * quickSort - Entry point
 * Description: quick sort starting point
 * @array: array to sort
 * @s: first index of the partition
 * @e: last index of the partition
 * @size: size of the entire array
 * Return: nothing
 */
void quickSort(int *array, int s, int e, size_t size)
{
	int pivot_idx;

	if (s >= e || s < 0 || e < 0)
		return;

	pivot_idx = partition(array, s, e, size);
	quickSort(array, s, pivot_idx - 1, size);
	quickSort(array, pivot_idx, e, size);
}
/**
 * quick_sort_hoare - Entry point
 * Description: quick sort starting point
 * @array: array to sort
 * @size: length of the array
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size <= 1)
		return;
	quickSort(array, 0, size - 1, size);
}
