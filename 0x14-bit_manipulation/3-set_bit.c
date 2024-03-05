#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * @n: Pointer to number to be modified
 * @index: The bit to set to 1
 * Return: 1 if it worked, -1 if an error occurred
*/
int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
{
return (-1);
}
*n = ((1UL << index) | *n);
return (1);
}
