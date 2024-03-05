#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 *
 * @b: Binary string to convert.
 *
 * Return: The converted unsigned integer, or 0 if the input is invalid.
 */
unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int dec_val = 0;

	if (!b)
		return (0);
	while (b[i])
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[i] - '0');
		i++;
	}

	return (dec_val);
}
