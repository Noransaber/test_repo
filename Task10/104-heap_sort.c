#include "sort.h"

/**
* sortify - Heapfy function
* @array: Array to be sorted
* @heap: Heap
* @i: idx
* @size: Size of the array
*/

void sortify(int *array, int heap, int i, int size)
{
	int lar = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[lar])
		lar = left;
	if (right < heap && array[right] > array[lar])
		lar = right;
	if (lar != i)
	{
		t = array[i], array[i] = array[lar], array[lar] = t;
		print_array(array, size);
		sortify(array, heap, lar, size);
	}
}

/**
* heap_sort - sorts an array of integers in ascending
* order using the Heap sort algorithm
* @array: Array to be sorted
* @size: Size of array
*/

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		sortify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
			print_array(array, size);
		sortify(array, i, 0, size);
	}

}
