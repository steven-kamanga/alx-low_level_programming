#include <stdio.h>

int is_prime_number_recursive(int n, int i);

/**
 * is_prime_number - check if a number is prime
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	if (n == 2)
	{
		return (1);
	}

	return (is_prime_number_recursive(n, 2));
}

/**
 * is_prime_number_recursive - check if a number is prime (recursive helper)
 * @n: the number to check
 * @i: the divisor to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number_recursive(int n, int i)
{
	if (n % i == 0)
	{
		return (0);
	}

	if (i > n / 2)
	{
		return (1);
	}

	return (is_prime_number_recursive(n, i + 1));
}
