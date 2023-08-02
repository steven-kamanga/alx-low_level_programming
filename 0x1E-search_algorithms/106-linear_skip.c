#include "search_algos.h"
#include <math.h>

/**
 * linear_skip - function that searches for a value in a sorted
 *	list of integers using the Jump search algorithm.
 * @list: pointer to the head of the list
 * @value: the value to search for in the linked list
 * Return: if the value was found returns its index else returns NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *p, *wait;

if (!list)
	return (NULL);

p = list;
while (p->n < value && p->express)
{
	wait = p;
	p = p->express;
	printf("Value checked at index [%ld] = [%d]\n", p->index, p->n);
}

if (p->n >= value)
{
	printf("Value found between indexes [%ld] and [%ld]\n"
		   , wait->index, p->index);
	p = wait;
}
else
{
	wait = p;
	while (wait->next)
		wait = wait->next;
	printf("Value found between indexes [%ld] and [%ld]\n"
		   , p->index, wait->index);

}

while (p)
{
	printf("Value checked at index [%ld] = [%d]\n", p->index, p->n);
	if (p->n == value)
		return (p);
	p = p->next;
}

return (NULL);
}
