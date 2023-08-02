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
 * __binary - a function that searches for a value in a sorted
 *	array of integers using the Binary search algorithm
 * @array: array of integers
 * @low: low index
 * @high: high index
 * @value: value to search for
 * Return: if the value was found returns its index else returns -1
 */

int __binary(int *array, int low, int high, int value)
{
int mid;

if (high < low)
	return (-1);

print_array(array, low, high);
mid = low + (high - low) / 2;


if (array[mid] == value && (mid == low || array[mid - 1] != value))
	return (mid);
if (array[mid] < value)
	return (__binary(array, mid + 1, high, value));
return (__binary(array, low, mid, value));


}


/**
 * advanced_binary - a function that searches for a value in a sorted
 *	array of integers.
 * @array: array of integers
 * @size: size of the array
 * @value: the value to search for in the array
 * Return: if the value was found returns its index else returns -1
 */

int advanced_binary(int *array, size_t size, int value)
{

if (!array || !size)
	return (-1);


return (__binary(array, 0, size - 1, value));

}
