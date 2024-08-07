#include <stddef.h>
#include <limits.h>
#include "sort.h"
/**
 * selection_sort - sorts an array using selection sorts
 * @array: the array to sort
 * @size: the size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallestIndex;
	int tmp;

	if (!array || !size || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallestIndex = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[smallestIndex])
				smallestIndex = j;
		if (smallestIndex != i)
		{
			tmp = array[i];
			array[i] = array[smallestIndex];
			array[smallestIndex] = tmp;
			print_array(array, size);
		}
	}
}
