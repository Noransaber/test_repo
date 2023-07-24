#include "sort.h"


/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, base, tmp, check = 0;

	if (size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		base = i;
		check = 0;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[base])
			{
				base = j;
				check = 1;
			}
		}
		tmp = array[i];
		array[i] = array[base];
		array[base] = tmp;
		if (check == 1)
			print_array(array, size);
	}
}
