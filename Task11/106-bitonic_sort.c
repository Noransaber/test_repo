#include "sort.h"

void swap(int *l, int *r);
void merge_bitonic(int *array, int low, int count, int dir, size_t size);
void b_sort(int *array, int low, int count, int dir, size_t size);

/**
* swap - Swaps array element
* @l: left element idx to swap
* @r: right element idx to swap
*/

void swap(int *l, int *r)
{
	int temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

/**
* merge_bitonic - Merge function
* @array: Array to be merged
* @low: Left mostl index
* @count: Count
* @dir: Direction, ascending 1 descending 0
* @size: size of total array for printing
*/

void merge_bitonic(int *array, int low, int count, int dir, size_t size)
{
	int i, n;

	if (count > 1)
	{
		n = count / 2;
		for (i = low; i < low + n; i++)
		{
			if (((array[i] > array[i + n]) && dir == 1) ||
			(dir == 0 && (array[i] < array[i + n])))
				swap(&array[i], &array[i + n]);
		}
		merge_bitonic(array, low, n, dir, size);
		merge_bitonic(array, low + n, n, dir, size);
	}
}

/**
* b_sort - Bitonic sort
* @array: array to be sorted
* @low: left most index
* @count: Count
* @dir: Direction, ascending 1 descending 0
* @size: size of array
*/

void b_sort(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		b_sort(array, low, n, 1, size);
		b_sort(array, low + n, n, 0, size);
		merge_bitonic(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
* bitonic_sort - sorts an array of integers in ascending
* order using the Bitonic sort algorithm
* @array: Array to be sorted
* @size: Size of the array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	b_sort(array, 0, size, 1, size);
}
