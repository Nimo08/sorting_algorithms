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
	int pivot_idx = e;
	int i = s - 1; /*last smaller idx*/
	int j; /*last bigger idx*/;

	for (j = s; j < pivot_idx; j++)
	{
		if (array[j] <= array[pivot_idx])
		{
			int temp;

			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	i++;
	if (i != pivot_idx)
	{
		int temp;

		temp = array[i];
		array[i] = array[pivot_idx];
		array[pivot_idx] = temp;
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

	if (s >= e || s < 0)
		return;
	pivot_idx = partition(array, s, e, size);

	quickSort(array, s, pivot_idx - 1, size);
	quickSort(array, pivot_idx + 1, e, size);
}
/**
 * quick_sort - Entry point
 * Description: quick sort starting point
 * @array: array to sort
 * @size: length of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
