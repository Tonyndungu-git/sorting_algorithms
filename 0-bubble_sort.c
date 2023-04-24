#include "sort.h"

/**
 * bubble_sort - function that sorts an array by using bubble sort algorithm.
 * @array: array to be sorted.
 * @size: size of the array.
 * Return: Void.
 */

void bubble_sort(int *array, size_t size)
{

	size_t i;
	int temp;
	size_t j;

	for  (j = 0; j < size - 1; j++)
	{
		for (i = 0; i < size - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

			}

		}
		if (array[size - 1] < array[size - 2])
			return;

	}


}
