#include "sort.h"
/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: it's the length of the array
 * Return: Void
 **/

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursion_h(array, 0, size - 1, size);
}

/**
 * quicksort_recursion - it's sorting the array recursiovely
 * @array: the array to bes sorted
 * @first: first(lowest) element(idx) in the array
 * @last: Last element of the array (highest)
 * @size: The length of the array
 * Return: Nothing
 **/
void quicksort_recursion_h(int *array, int first, int last, size_t size)
{
	int pivot_index;

	if (first < last)
	{
		pivot_index = partition_h(array, first, last, size);
		quicksort_recursion_h(array, first, pivot_index, size);
		quicksort_recursion_h(array, pivot_index + 1, last, size);
	}
}
/**
 * partition - to divie our list
 * @array: Our array to be sorted
 * @first: first elem of the array
 * @last: last ele of the array
 * @size: The length of the array
 * Return: the pivot index
 **/
size_t partition_h(int *a, size_t first, size_t last, size_t size)
{

	int pivot, swap;

	pivot = a[last];

	while (first <= last)
	{
		while (a[first] < pivot)
			first++;
		while (a[last] > pivot)
			last--;

		if (first <= last)
		{
			if (first != last)
			{
				swap = a[first];
				a[first] = a[last];
				a[last] = swap;
				print_array(a, size);
			}
			first++;
			last--;
		}
	}
	return (last);
}
