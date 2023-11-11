#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array using a given comparison function
 * @array: array to search
 * @size: size of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: the index of the first element for which the comparison
 *         function does not return 0, or -1 if no such element is found
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
