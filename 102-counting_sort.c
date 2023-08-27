#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t i, k = 0;
	int *count, *array_2;

	if (size <= 1)
		return;
	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > k)
		{
			k = array[i];
		}
	}
	count = malloc((k + 1) * sizeof(int));
	if (count == NULL)
		return;
	array_2 = malloc(size * sizeof(int));
	if (array_2 == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		array_2[--count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = array_2[i];
	}
	print_array(count, k + 1);
	free(count);
	free(array_2);
}
