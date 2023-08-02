#include "main.h"
/**
 * rot13 - Write a function that encodes a string using rot13
 *
 * @hi: This is my input string
 *
 * Return: String converted to rot13
 *
 */

char *rot13(char *s)
{
	int index, count;

	char minus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char mayus[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (index = 0; s[index] != '\0'; ++index)
	{
		for (count = 0; minus[count] != '\0' ; count++)
		{
			if (s[index] == minus[count])
			{
				s[index] = mayus[count];
				break;
			}
		}
	}
	s[index] = '\0';
	return (s);
}