#include "sort.h"

void swap(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

size_t partition(int* array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo;
	int j;

	for(j = lo; j < hi; ++j)
	{
		if(array[j] <= pivot)
		{
			if(i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			++i;
		}
	}
	if(i != hi)
	{
		swap(&array[i], &array[hi]);
		print_array(array, size);
	}
	return i;
}

void quicksort(int* array, int lo, int hi, size_t size)
{
	size_t p;

	if(lo >= hi || lo < 0)
		return;

	p = partition(array, lo, hi, size);

	quicksort(array, lo, p - 1, size);
	quicksort(array, p + 1, hi, size);
}


void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}