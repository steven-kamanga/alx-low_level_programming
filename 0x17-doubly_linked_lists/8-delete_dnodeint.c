#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked list
 *
 * @head: head of the list
 * @index: index of the node to delete
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *h1, *h2;
unsigned int i;

if (*head == NULL)
return (-1);

h1 = *head;

if (index == 0)
{
*head = h1->next;
if (*head != NULL)
(*head)->prev = NULL;
free(h1);
return (1);
}

for (i = 0; h1 != NULL && i < index; i++)
{
h2 = h1;
h1 = h1->next;
}

if (h1 == NULL)
return (-1);

h2->next = h1->next;

if (h1->next != NULL)
h1->next->prev = h2;

free(h1);
return (1);
}
