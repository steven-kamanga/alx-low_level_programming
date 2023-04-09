#include "hash_tables.h"

/**
 * make_hash_node - creates a new hash node
 * @key: key for the node
 * @value: for the node
 *
 * Return: the new node, or NULL on failure
 */
hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);

		return (NULL);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);

		return (NULL);
	}
	node->next = NULL;

	return (node);
}

/**
 * hash_table_set - sets a key to a value in the hash table
 * @ht: hash table to add elemt to
 * @key: key for the data
 * @value: data to store
 *
 * Return: 1 if successful, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *node, *tmp;

    if (ht == NULL || key == NULL || value == NULL || *key == '\0')
        return (0);
    index = key_index((const unsigned char *)key, ht->size);
    node = make_hash_node(key, value);
    if (node == NULL)
        return (0);
    if (ht->array[index] == NULL)
    {
        ht->array[index] = node;

        return (1);
    }
    tmp = ht->array[index];
    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = strdup(value);
            free(node->key);
            free(node->value);
            free(node);
            
            return (1);
        }
        tmp = tmp->next;
    }
    node->next = ht->array[index];
    ht->array[index] = node;

    return (1);
}
