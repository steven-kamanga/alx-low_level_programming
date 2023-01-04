#include <stdbool.h>
#include <string.h>

/**
 * is_palindrome - check if a string is a palindrome
 * @s: the string to check
 *
 * Return: true if s is a palindrome, false otherwise
 */
bool is_palindrome(char *s)
{
    int len = strlen(s);
    int i;

    for (i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }

    return true;
}
