#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 *main - Entry point
 *
 *Description: Print values of n status
 *
 *Return: Always 0 (Success)
 *
 */

int main(void)
{
	int n;
	srand(time(0));
	n = rand() - RAND_MAX /2;

	/*Code goes here*/
	if(n > 0)
		printf("%i is positive\n", n);
	else if(n == 0)
		printf("%i is zero\n", n);
	else
		printf("%i is negative\n", n);
	return (0);
}
