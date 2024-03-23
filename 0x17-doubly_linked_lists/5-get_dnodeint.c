#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - returns nth node of a dlistint_t linked list
 * @head: pointer to head of list
 * @index: index of node to return
 * Return: nth node of list, or NULL if node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int i;

if (head == NULL)
return (NULL);

if (index == 0)
return (head);

for (i = 0; i < index; i++)
{
head = head->next;
if (head == NULL)
return (NULL);
}

return (head);
}
