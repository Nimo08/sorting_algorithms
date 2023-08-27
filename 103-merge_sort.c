#include "sort.h"
/**
 * merge - Entry point
 * Description: merge sort starting point
 * @array: array to sort
 * @copy: copy array
 * @s: start idx
 * @e: endidx + 1
 * @m: middleidx
 * Return: nothing
 */
void merge(int *array, int *copy, int s, int e, int m)
{
	int i = s, j = m, k, flag;

	printf("Merging...\n");
	printf("[left]: ");
	flag = 0;
	for (i = s; i < m; i++)
	{
		if (flag)
			printf(", ");
		printf("%d", array[i]);
		flag = 1;
	}
	printf("\n[right]: ");
	flag = 0;
	for (i = m; i < e; i++)
	{
		if (flag)
			printf(", ");
		printf("%d", array[i]);
		flag = 1;
	}
	printf("\n");
	i = s;
	j = m;
	for (k = s; k < e; k++)
	{
		if (i < m && (j >= e || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i++;
		}
		else
		{
			copy[k] = array[j];
			j++;
		}
	}
	for (k = s; k < e; k++)
		array[k] = copy[k];
}
/**
 * mergeSort - Entry point
 * Description: merge sort starting point
 * @array: array to sort
 * @copy: copy array
 * @start: start idx
 * @end: endidx + 1
 * Return: nothing
 */
void mergeSort(int *array, int *copy, int start, int end)
{
	int middle, k;

	if (end - start <= 1)
		return;
	middle = (start + end) / 2;
	mergeSort(array, copy, start, middle);
	mergeSort(array, copy, middle, end);
	merge(array, copy, start, end, middle);
	printf("[Done]: ");
	for (k = start; k < end; k++)
	{
		if (k != start)
		printf(", ");
		printf("%d", array[k]);
	}
	printf("\n");
}
/**
 * merge_sort - Entry point
 * Description: merge sort starting point
 * @array: array to sort
 * @size: length of the array
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t k;
	int *arr = malloc(sizeof(int) * size);
	/*create copy arr*/
	for (k = 0; k < size; k++)
		arr[k] = array[k];
	/*sort*/
	mergeSort(array, arr, 0, size);
	free(arr);
}
