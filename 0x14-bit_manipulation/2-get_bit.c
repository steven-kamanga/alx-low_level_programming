#include "main.h"

/**
 * get_bit - Returns a value of a given bit at a given index
 * @n: Value of a given big
 * @index: value of the index
 * Return: the value of the bit at index or -1 if an error occurred
 */

int get_bit(unsigned long int n, unsigned int index)
{
if (index >= (sizeof(unsigned long int) * 8))
{
return (-1);
}
if ((n >> index) == 0)
{
return (0);
}

return (1);
}
