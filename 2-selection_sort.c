#include "sort.h"
/**
* selection_sort - sorts an array of integers in ascending
* order
* @array: pointer to the first element of the integer array
* to sort
* @size: number of elements in the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, smaller_index, tmp;

	for (i = 0; i < size - 1; i++)
	{
		smaller_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smaller_index])
			{
				smaller_index = j;
			}
		}
		if (smaller_index != i)
		{
			tmp = array[i];
			array[i] = array[smaller_index];
			array[smaller_index] = tmp;
			print_array(array, size);
		}
	}
}
