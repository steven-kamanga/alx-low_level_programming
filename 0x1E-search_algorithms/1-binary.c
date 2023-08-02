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
 * binary_search - a function that searches for a value in a sorted
 *	array of integers using the Binary search algorithm
 * @array: array of integers
 * @size: size of the array
 * @value: the value to search for in the array
 * Return: if the value was found returns its index else returns -1
 */

int binary_search(int *array, size_t size, int value)
{
int mid;
int low, high;

if (!array)
	return (-1);

low = 0;
high = size - 1;


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
