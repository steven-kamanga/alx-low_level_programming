#include "search_algos.h"
#include <math.h>

/**
 * jump_search -  a function that searches for a value in a
 * sorted array of integers using the Jump search algorithm
 * @array: The array of integers
 * @size: size of the array
 * @value: value to search for in the array
 * Return: index of the value
 */

int jump_search(int *array, size_t size, int value)
{
int a, b;

if (!array || !size)
	return (-1);

a = 0;
b = sqrt(size);


while (a < (int)size && array[a] < value)
{
	printf("Value checked array[%d] = [%d]\n", a, array[a]);
	a += b;
}

b = a - b;
printf("Value found between indexes [%d] and [%d]\n", b, a);
for (; b < (int)size ; b++)
{
	printf("Value checked array[%d] = [%d]\n", b, array[b]);
	if (array[b] == value)
		return (b);
}

return (-1);
}
