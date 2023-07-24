#include "sort.h"
/**
 * merge_sort -  sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: length of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *cpy_arr;

	if (array == NULL || size < 2)
		return;

	cpy_arr = malloc(sizeof(int) * size);
	if (cpy_arr == NULL)
		return;

	for (i = 0; i < size; i++)
		cpy_arr[i] = array[i];

	merge_recrusion(0, size, array, cpy_arr);

	free(cpy_arr);
}
/**
 * merge_recrusion - split the array recrusively
 * @l: left side
 * @r: right side
 * @a: Original array
 * @cpy_arr: copied one
 **/
void merge_recrusion(size_t l, size_t r, int *a, int *cpy_arr)
{
	size_t m;

	if (r - l < 2)
		return;

	m = (l + r) / 2;

	merge_recrusion(l, m, a, cpy_arr);
	merge_recrusion(m, r, a, cpy_arr);
	merge(l, m, r, a, cpy_arr);

	for (m = l; m < r; m++)
		cpy_arr[m] = a[m];
}
/**
 * merge - to merge between subarrays
 * @l: left part
 * @m: middle part
 * @r: right part
 * @dest: array where merged result will be stored
 * @org: Original array
 **/
void merge(size_t l, size_t m, size_t r, int *dest, int *org)
{
	size_t f, t, o;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(org + l, m - l);
	printf("[right]: ");
	print_array(org + m, r - m);

	f = l;
	t = m;
	for (o = l; o < r; o++)
	{
		if (f < m && (t >= r || org[f] <= org[t]))
		{
			dest[o] = org[f];
			f++;
		}
		else
		{
			dest[o] = org[t];
			t++;
		}
	}

	printf("[Done]: ");
	print_array(dest + l, r - l);
}
