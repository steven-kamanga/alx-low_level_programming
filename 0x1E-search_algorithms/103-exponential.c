#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @low: index of the first element
 * @high: index of the last element
 */

void print_array(const int *array, int low, int high)
{
	int i = low;

	printf("Searching in array: ");
	while (array && low <= high)
	{
		if (low > i)
			printf(", ");
		printf("%d", array[low]);
		++low;
	}
	printf("\n");
}


/**
 * __binary_search - a function that searches for a value in a sorted
 *	array of integers using the Binary search algorithm
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @value: the value to search for in the array
 * Return: if the value was found returns its index else returns -1
 */

int __binary_search(int *array, int low, int high, int value)
{
int mid;

if (!array)
	return (-1);


while (low <= high)
{
	print_array(array, low, high);
	mid = (low + high) / 2;
	if (array[mid] == value)
		return (mid);
	if (array[mid] < value)
		low = mid + 1;
	if (array[mid] > value)
		high = mid - 1;
}

return (-1);
}


/**
 * exponential_search -  a function that searches for a value in a
 * sorted array of integers using the exponential search algorithm
 * @array: The array of integers
 * @size: size of the array
 * @value: value to search for in the array
 * Return: index of the value
 */

int exponential_search(int *array, size_t size, int value)
{
int b, x;

if (!array || !size)
	return (-1);

b = 1;

while (b < (int)size && array[b] <= value)
{
	printf("Value checked array[%d] = [%d]\n", b, array[b]);
	b *= 2;
}

x = b < (int)size ? b : (int)size - 1;

printf("Value found between indexes [%d] and [%d]\n", b / 2, x);

return (__binary_search(array, b / 2, x, value));
}
