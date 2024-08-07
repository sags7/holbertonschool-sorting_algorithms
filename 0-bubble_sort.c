#include <stddef.h>
#include "sort.h"

/**
 * swapInt - swaps the values of a and b
 * @a: first value to swapint
 * @b: second value to swap
 */
void swapInt(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/**
 * bubble_sort - sorts and array using bubble sort algo
 * @array: the array to sort
 * @size: the size of array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, j;

	if (!array || !size)
		return;
	for (j = 1; j < size; j++)
	{
		swapped = 0;
		for (i = 1; i < size; i++)
			if (array[i - 1] > array[i])
			{
				swapInt(&array[i - 1], &array[i]);
				print_array(array, size);
				swapped = 1;
			}
		if (!swapped)
			break;
	}
}
