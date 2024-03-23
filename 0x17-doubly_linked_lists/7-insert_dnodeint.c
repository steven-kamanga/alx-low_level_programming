#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index of the new node
 * @n: value of the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current;
    unsigned int i;

    if (h == NULL)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    current = *h;
    for (i = 0; i < idx && current != NULL; i++)
        current = current->next;

    if (i < idx)
    {
        free(new_node);
        return (NULL);
    }

    if (current == *h)
    {
        new_node->next = *h;
        if (*h != NULL)
            (*h)->prev = new_node;
        *h = new_node;
    }
    else if (current == NULL)
    {
        current = *h;
        while (current->next != NULL)
            current = current->next;

        current->next = new_node;
        new_node->prev = current;
    }
    else
    {
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
    }

    return (new_node);
}
