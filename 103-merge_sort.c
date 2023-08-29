#include "sort.h"
/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: Lenth of the array
 * Return: Nothing
 **/
void merge_sort(int *array, size_t size,)
{
	int *dest;
	if (array == NULL || size < 2)
		return;
	dest = (int *)malloc(size * sizeof(int *));

	if (dest == NULL)
	{
		perror("Memory allocation failed");
		return;
	}

	merge_sort_recurstion(array, 0, size - 1, dest);
	free(dest);
}

/**
 * merge_sort_recurstion - dividing the array into small one
 * @a: array
 * @l: left side of the array
 * @r: right side of the array
 * Return: Void
 **/
void merge_sort_recurstion(int a[], int l, int r, int *dest)
{
	int m;
	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort_recurstion(a, l, m);
		merge_sort_recurstion(a, m + 1, r);
		Dmerge(l, m + 1, r + 1, dest, a);
	}
}
/**
 * merge - to merger between sub arrays
 * @l: left side
 * @m: medlle side
 * @r: right side
 * Return: Nothing
 **/
void merge(int a[], int l, int m, int r)
{
	int i, o, f, t;
	int left_len = m - l + 1;
	int right_len = r - m;

	int *left_arr = (int *)malloc(left_len * sizeof(int *));
	int *right_arr = (int *)malloc(right_len * sizeof(int *));

	for (i = 0; i < left_len; i++)
		left_arr[i] = a[l + 1];
	for (i = 0; i < right_len; i++)
		right_arr[i] = a[m + 1 + i];

	while (f < left_len && t < right_len)
	{
		if (left_arr[f] < right_arr[t])
		{
			a[o] = left_arr[f];
			f++;
		}
		else
		{
			a[o] = right_arr[t];
			t++;
		}
		o++;
	}
	while (f < left_len)
	{
		a[o] = left_arr[f];
		f++;
		o++;
	}
	while (t < right_len)
	{
		a[o] = right_arr[t];
		t++;
		o++;
	}
	free(left_arr);
	free(right_arr);
}
