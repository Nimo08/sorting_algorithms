#include "sort.h"
/**
* merge - Entry point
* Description: merge sort starting point
* @array: array to sort
* @count: copy array
* @lowIDx: start idx
* @direction: sorting direction
* Return: nothing
*/
void merge(int *array, int lowIDx, int count, int direction)
{
	int i, k, temp;

	if (count <= 1)
		return;
	k = count / 2;
	for (i = lowIDx; i < lowIDx + k; i++)
	{
		if (array[i] > array[i + k] && direction == 1)
		{
			temp = array[i];
			array[i] = array[i + k];
			array[i + k] = temp;
		}
		else if (!(array[i] > array[i + k]) && direction == 0)
		{
			temp = array[i];
			array[i] = array[i + k];
			array[i + k] = temp;
		}
	}
	merge(array, lowIDx, k, direction);
	merge(array, lowIDx + k, k, direction);
}
/**
* bitonicSort - Entry point
* Description: bitonic sort starting point
* @array: array to sort
* @count: copy array
* @lowIDx: start idx
* @direction: sorting direction
* @s: size
* Return: nothing
*/
void bitonicSort(int *array, int lowIDx, int count, int direction, int s)
{
	int k, i, flag = 0;

	if (count <= 1)
		return;
	k = count / 2;
	printf("Merging [%d/%d] (", count, s);
	if (direction == 1)
		printf("UP):\n");
	else
		printf("DOWN):\n");
	for (i = lowIDx; i < lowIDx + count; i++)
	{
		if (flag)
			printf(", ");
		printf("%d", array[i]);
		flag = 1;
	}
	printf("\n");

	bitonicSort(array, lowIDx, k, 1, s);
	bitonicSort(array, lowIDx + k, k, 0, s);
	merge(array, lowIDx, count, direction);
	printf("Result [%d/%d] (", count, s);
	if (direction == 1)
		printf("UP):\n");
	else
		printf("DOWN):\n");
	flag = 0;
	for (i = lowIDx; i < count + lowIDx; i++)
	{
		if (flag)
			printf(", ");
		printf("%d", array[i]);
		flag = 1;
	}
    printf("\n");
}
/**
* bitonic_sort - Entry point
* Description: merge sort starting point
* @array: array to sort
* @size: length of the array
* Return: nothing
*/
void bitonic_sort(int *array, size_t size)
{
	bitonicSort(array, 0, size, 1, size);
}
