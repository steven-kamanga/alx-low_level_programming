#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: Print 0-9 using putchar while using int variable
 *
 * Return: Always 0 (Successful)
 *
*/

int main(void)
{
	int digit = 0;

	while (digit <=9)
	{
		putchar(digit + '0');
		++digit;
	}
	putchar('\n');

	return (0);
}
