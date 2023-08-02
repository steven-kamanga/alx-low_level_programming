#include "search_algos.h"
#include <math.h>


/**
 * jump_list - function that searches for a value in a sorted
 *	list of integers using the Jump search algorithm.
 * @list: pointer to the head of the list
 * @size: number of nodes
 * @value: the value to search for in the linked list
 * Return: if the value was found returns its index else returns -1
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
int a, b, i;
listint_t *p, *wait;

if (!list || !size)
	return (NULL);

a = 0;
b = sqrt(size);
p = list;

while (a < (int)size &&  p->n < value)
{
	i = a;
	a += b;

	wait = p;
	for ( ; i < a && p->next ; i++)
		p = p->next;
	printf("Value checked at index [%ld] = [%d]\n", p->index, p->n);
}

	printf("Value found between indexes [%ld] and [%ld]\n"
		   , wait->index, p->index);
while (wait->index != p->index)
{
	printf("Value checked at index [%ld] = [%d]\n", wait->index, wait->n);
	if (wait->n == value)
		return (wait);
	wait = wait->next;
}

printf("Value checked at index [%ld] = [%d]\n", p->index, p->n);
return (NULL);
}
