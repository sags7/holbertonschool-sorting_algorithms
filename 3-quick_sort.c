#include "sort.h"

/**
 * swap - swaps the values of two ints
 * @a: the first int
 * @b: the second int
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partitions the array into smaller parts
 * @arr: the array to partition
 * @start: the start of the subarray
 * @end: the end of the array
 * Return: the index of the partition within the array
 */
int partition(int *arr, int start, int end)
{
	int pivot = arr[end];
	int j = start, i = start - 1;

	for (j = start; j <= end - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

/**
 * qSortRec - recursive function that implements the quicksort algorithm
 * @arr: the section of the array to sort
 * @start: the starting index of the subsection of the array
 * @end: the ending index of the subsection of the array
 * @size: the size of the array
 */
void qSortRec(int *arr, int start, int end, size_t size)
{
	if (start < end)
	{
		int pi = partition(arr, start, end);

		print_array(arr, size);
		qSortRec(arr, start, pi - 1, size);
		qSortRec(arr, pi + 1, end, size);
	}
}

/**
 * quick_sort - sorts an arry using the quick sort algorithm
 * @array: the array to sort
 * @size: the size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	qSortRec(array, 0, size - 1, size);
}
