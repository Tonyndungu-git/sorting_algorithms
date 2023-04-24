#include "sort.h"

/**
 * selection_sort - function that sorts an array by using selection sort.
 * @array: array to be sorted.
 * @size: size of the array.
 * Return: Void.
 */


void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL || size < 2)
		return;


	for (i = 0; i < size - 1; i++)
	{

		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;


		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);

		}
	}
}
