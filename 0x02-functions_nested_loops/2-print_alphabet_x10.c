#include "main.h"

/**
 * main - Entry point
 * 
 * Description: Function that prints 10 times the alphabet, in lowercase.
 * 
 * Return: Always 0 (Success)
 * 
*/

void print_alphabet_x10(void)
{
    int i;
    int j;

    for (i = 0; j < 10; i++)
    {
        for ( j = 0; j <= 'z'; j++)
        {
            _putchar(j);
        }
        _putchar('\n');
    }
}