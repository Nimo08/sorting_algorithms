#include "sort.h"
/**
 * selection_sort - Entry point
 * Description: selection sort algorithm
 * @array: array to sort
 * @size: length of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int min_val, temp;

	if (size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_val = array[i];
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min_val)
			{
				min_val = array[j];
				min_idx = j;
			}
		}
		if (i == min_idx)
			continue;
		temp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = temp;
		print_array(array, size);
	}
}
