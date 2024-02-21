#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @x: The first integer to swap
 * @y: The second integer to swap
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - selection sort algorithm
 * @array: An array
 * @size: The size
 */
void selection_sort(int *array, size_t size)
{
	int *arc;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		arc = array + i;
		for (j = i + 1; j < size; j++)
			arc = (array[j] < *arc) ? (array + j) : arc;

		if ((array + i) != arc)
		{
			swap_ints(array + i, arc);
			print_array(array, size);
		}
	}
}
