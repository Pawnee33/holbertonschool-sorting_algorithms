#include "sort.h"
/**
* bubble_sort - Sorts an array of integers in ascending
* order using Bubble Sort
* @array: pointer to the first element of the integer array
* to sort
* @size: number of elements in the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;

	for (i = 0; i < size - 1; i++)
	{
		size_t check = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				check = 1;
				print_array(array, size);
			}
		}
		if (check == 0)
			break;
	}
}
