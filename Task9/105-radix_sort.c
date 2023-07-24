#include "sort.h"
/**
 * get_max - fin max number
 * @a: array where we search about max num
 * @s: lenth of the array
 * Return: max number
 **/


int get_max(const int *a, size_t s)
{
	size_t i;
	int max;

	max = a[0];
	for (i = 0; i < s; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return (max);
}
/**
 * radix_sort - sorts an array of integers in ascending
 * @array: Array to be sorted
 * @size: size of the array
 **/
void radix_sort(int *array, size_t size)
{
	size_t i;
	int j, max;
	int exp = 1;
	int *output = malloc(size * sizeof(int));

	if (size < 2)
		return;

	max = get_max(array, size);
	if (output == NULL)
		return;
	while (max / exp > 0)
	{
		int count[10] = {0};

		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;

		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];

		for (j = size - 1; j >= 0; j--)
		{
			output[count[(array[j] / exp) % 10] - 1] = array[j];
			count[(array[j] / exp) % 10]--;
		}

		for (i = 0; i < size; i++)
			array[i] = output[i];

		print_array(array, size);

		exp *= 10;
	}
	free(output);
}
