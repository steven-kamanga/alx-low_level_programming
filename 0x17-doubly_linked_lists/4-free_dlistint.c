#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
dlistint_t *current;

while (head != NULL)
{
current = head;
head = head->next;
free(current);
}
}
