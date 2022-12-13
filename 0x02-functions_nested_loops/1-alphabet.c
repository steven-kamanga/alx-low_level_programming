#include"main.h"

/**
 * main - Entry point
 *
 * Description: Print_alphabet - Utilizes on the _putchar to print the alphabet a - z
 *
 * Return: Always 0 (Successful)
 *
*/

void print_alphabet(void)
{
	int ch;

	for(ch = 'a'; ch <= 'z'; ++ch)
		_putchar(ch);
	_putchar('\n');
}
