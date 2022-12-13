#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i;
    char str[] = "_putchar";

    for (i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
    }
    putchar('\n');

    return (0);
}

