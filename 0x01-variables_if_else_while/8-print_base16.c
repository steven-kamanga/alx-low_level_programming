#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print numbers of base16 lowercase
 *
 * Return: Always 0 (Success)
 *
*/

int main(void)
{
	int digit = 48;

	while(digit <= 102)
	{
		putchar(digit);

		if(digit == 57)
			digit += 39;
		++digit;
	}
	putchar('\n');

	return (0);
}
