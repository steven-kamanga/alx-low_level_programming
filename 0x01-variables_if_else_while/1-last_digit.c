#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 *
 *main - Entry point
 *
 *Description: Promt last number
 *
 *Return: Always 0(Success)
 *
 **/

int main(void)
{
	int n, digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	digit = n % 10;

	if(digit > 5)
		printf("Last digit of %i is %i and is greater than 5\n", n, digit);
	else if(digit == 0)
		printf("Last digit of %i is %i and is 0\n", n, digit);
	else if(digit < 6 && digit != 0)
		printf("Last digit of %i is %i and is less than 6 not 0\n", n, digit);

	return (0);

}
