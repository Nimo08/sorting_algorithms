#include "sort.h"
int get_max(int *array, size_t size);
void count_sort(int *array, size_t size, size_t pos);
/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int pos;
	int max_val = get_max(array, size);

	if (size <= 1)
		return;
	for (pos = 1; (max_val / pos) > 0; pos *= 10)
	{
		count_sort(array, size, pos);
		print_array(array, size);
	}
}
/**
 * count_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * @pos: place value
 * Return: nothing
 */
void count_sort(int *array, size_t size, size_t pos)
{
	size_t i, max = 0;
	int *count, *array_2;

	if (size <= 1 || pos == 0)
		return;
	count = malloc((10) * sizeof(int));
	if (count == NULL)
		return;
	array_2 = malloc(size * sizeof(int));
	if (array_2 == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
	{
		++count[array[i] / pos % 10];
	}
	for (i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		array_2[--count[array[i] / pos % 10]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = array_2[i];
	}
	free(count);
	free(array_2);
}
/**
 * get_max - get maximum value in array
 * @array: array of integers
 * @size: size of array
 * Return: maximum value
 */
int get_max(int *array, size_t size)
{
	int i;
	int max = array[0];

	if (size <= 0)
		return (0);
	for (i = 0; (size_t)i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}
