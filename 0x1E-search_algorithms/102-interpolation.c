#include "search_algos.h"


/**
 * interpolation_search -  a function that searches for a value in a
 * sorted array of integers using the Interpolation search algorithm
 * @array: The array of integers
 * @size: size of the array
 * @value: value to search for in the array
 * Return: index of the value
 */

int interpolation_search(int *array, size_t size, int value)
{
int low, high, p;

if (!array || !size)
	return (-1);

low = 0;
high = size - 1;

while (low != high && array[low] <= value && array[high] >= value)
{
	p = low + (((double)(high - low) / (array[high]
	    - array[low])) * (value - array[low]));
	printf("Value checked array[%d] = [%d]\n", p, array[p]);
	if (value > array[p])
	{
		low = p + 1;
	}
	else if (array[p] > value)
	{
		high = p - 1;
	}
	else
		return (p);
}
p = low + (((double)(high - low) / (array[high]
	- array[low])) * (value - array[low]));
printf("Value checked array[%d] is out of range\n", p);
return (-1);
}
