#include "sort.h"

/**
 * swap - Swap to integers variables
 * @a: The first integer
 * @b: The second integer
*/
void swap(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

/**
 * partition - Lomuto partition algo
 * @array: The int array to partition
 * @lo: The lowest index to condsider
 * @hi: The highest index to condsider
 * @size: The size of the array
 * Return: Final index of pivot
*/
size_t partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo;
	int j;

	for (j = lo; j < hi; ++j)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			++i;
		}
	}
	if (i != hi)
	{
		swap(&array[i], &array[hi]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - Quicksort algo
 * @array: The array to sort
 * @lo: The lowest index to condsider
 * @hi: The highest index to condsider
 * @size: Size of the array
*/
void quicksort(int *array, int lo, int hi, size_t size)
{
	size_t p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(array, lo, hi, size);

	quicksort(array, lo, p - 1, size);
	quicksort(array, p + 1, hi, size);
}

/**
 * quick_sort - Quicksort algo wrapper
 * @array: The array to sort
 * @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
