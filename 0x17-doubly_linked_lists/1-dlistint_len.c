#include <stdio.h>
#include "lists.h"

/**
 * dlisting_len - Function that returns
 * the number or elements in a linked list
 * @h: pointer to the list
 * Return: number of elements in a linked list
 *
*/

size_t dlisting_len(const dlistint_t *h)
{
	int count = 0;

	if (h == NULL)
		return (count);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
