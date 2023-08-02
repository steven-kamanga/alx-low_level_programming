#include "search_algos.h"

/**
 * linear_search - searches an array of integers for a value
 * @array: array of integers
 * @size: size of array
 * @value: search value
 * Return: index of value, -1 if not found
 */

int linear_search(int *array, size_t size, int value)
{
int i;

if (!array)
	return (-1);

for (i = 0 ; i < (int) size ; i++)
{
	if (array[i] != value)
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
	else
		{
			printf("Value checked array[%d] = [%d]\n", i, array[i]);
			return (i);
		}
}

return (-1);
}
