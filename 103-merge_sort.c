#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers
 * @subarr: A subarray
 * @buff: A buffer
 * @front: The front index
 * @mid: The middle index
 * @back: The back index
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (x = front, y = mid; x < mid && y < back; z++)
		buff[z] = (subarr[x] < subarr[y]) ? subarr[x++] : subarr[y++];
	for (; y < mid; y++)
		buff[z++] = subarr[x];
	for (; y < back; y++)
		buff[z++] = subarr[y];
	for (x = front, z = 0; x < back; x++)
		subarr[x] = buff[z++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - merge sort algorithm through recursion.
 * @subarr: A subarray
 * @buff: A buffer
 * @front: The front index
 * @back: The back index
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - merge sort algorithm.
 * @array: An array
 * @size: The size
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
