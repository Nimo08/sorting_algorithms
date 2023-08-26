#include "sort.h"
/**
 * sift_down - Entry point
 * Description: rearranges the heap
 * @array: array to sort
 * @start: starting index
 * @end: ending index
 * @n: size
 * Return: nothing
 */
void sift_down(int *array, int start, int end, int n)
{
	int leftChildIdx, tempIdx, swap, temp;

	tempIdx = start + 1;
	leftChildIdx = tempIdx * 2;
	while (leftChildIdx - 1 <= end)
	{
		swap = leftChildIdx - 1;
		if (leftChildIdx <= end) /*right child actual idx*/
		{
			if (array[leftChildIdx] > array[swap])
				swap = leftChildIdx;
		}
		if (array[start] >= array[swap])
			return;
		temp = array[swap];
		array[swap] = array[start];
		array[start] = temp;
		start = swap;
		tempIdx = start + 1;
		leftChildIdx = tempIdx * 2;
		print_array(array, n);
	}
}
/**
 * create_heap - Entry point
 * Description: creates the heap
 * @array: array to sort
 * @size: length of the array
 * Return: nothing
 */
void create_heap(int *array, size_t size)
{
	int start = size - 1;
	int n = size;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, n);
		start--;
	}
}
/**
 * heap_sort - Entry point
 * Description: heap sort starting point
 * @array: array to sort
 * @size: length of the array
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int temp, n;

	if (size <= 1)
		return;
	/*create the heap*/
	create_heap(array, size);
	/*order the list using sift down*/
	n = size;
	while (size > 0)
	{
		if (size - 1 != 0)
		{
			temp = array[0];
			array[0] = array[size - 1];
			array[size - 1] = temp;
			print_array(array, n);
			sift_down(array, 0, size - 2, n);
		}
		size--;
	}
}
