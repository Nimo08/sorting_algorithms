#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (size <= 1)
	{
		return;
	}
	while (gap < (size) / 3)
	{
		gap = (gap * 3) + 1;
	}
	while (gap > 0)
	{
		for (i = 0; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j > gap - 1 && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
