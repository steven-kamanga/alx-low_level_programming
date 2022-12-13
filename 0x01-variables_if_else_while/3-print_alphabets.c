#include <stdio.h>

/**
 *main - Entey point
 *
 *Descriptiom: Print alphabet
 *
 *Return: Always 0 (Success)
 *
*/

int main(void)
{
	char ch = 'a';
	char CH = 'A';

	/*prints a - z*/

	while (ch <= 'z')
	{
		putchar(ch);
		++ch;
	}
	/*primt A - Z*/
	while(CH < 'Z')
	{
		putchar(CH);
		++CH;
	}
	putchar('\n');

	return (0);
}
