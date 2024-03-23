#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlist
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes in the list (success)
 *
 * Description: This function prints all the elements of a dlistint_t list.
 * It starts from the head node and prints the data of each node.
 * It continues until all the nodes have been printed.
 * The function returns the number of nodes in the list.
 *
 * Example usage:
 *
 * dlistint_t *head = NULL;
 *
*/

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
