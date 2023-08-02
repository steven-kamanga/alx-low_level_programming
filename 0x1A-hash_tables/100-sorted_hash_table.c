#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the hash table
 *
 * Return: pointer to the newly created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *new_table = NULL;

    new_table = malloc(sizeof(shash_table_t));
    if (new_table == NULL)
        return (NULL);

    new_table->size = size;
    new_table->array = calloc(size, sizeof(shash_node_t *));
    if (new_table->array == NULL)
    {
        free(new_table);
        return (NULL);
    }

    return (new_table);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: key for the data
 * @value: data to be stored
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
    shash_node_t *node;

    node = malloc(sizeof(shash_node_t));
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
    node->sprev = NULL;
    node->snext = NULL;

    return (node);
}

/**
 * add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 * @table: the sorted hash table
 * @node: the node to add
 *
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
    shash_node_t *tmp;

    if (table->shead == NULL)
    {
        table->shead = node;
        table->stail = node;
        return;
    }
    tmp = table->shead;
    while (tmp != NULL)
    {
        if (strcmp(node->key, tmp->key) < 0)
        {
            if (tmp->sprev == NULL)
            {
                node->snext = tmp;
                tmp->sprev = node;
                table->shead = node;
                return;
            }
            node->snext = tmp;
            node->sprev = tmp->sprev;
            tmp->sprev->snext = node;
            tmp->sprev = node;
            return;
        }
        tmp = tmp->snext;
    }
    table->stail->snext = node;
    node->sprev = table->stail;
    table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *node, *tmp;

    if (ht == NULL || key == NULL || value == NULL || *key == '\0')
        return (0);
    index = key_index((const unsigned char *)key, ht->size);
    node = make_shash_node(key, value);
    if (node == NULL)
        return (0);
    if (ht->array[index] == NULL)
    {
        ht->array[index] = node;
        add_to_sorted_list(ht, node);
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
    add_to_sorted_list(ht, node);

    return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: hash table
 * @key: key to the data
 *
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *tmp;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);
    index = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[index];
    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }

    return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *tmp;

    if (ht == NULL)
        return;
    tmp = ht->shead;
    printf("{");
    while (tmp != NULL)
    {
        printf("'%s': '%s'", tmp->key, tmp->value);
        if (tmp->snext != NULL)
            printf(", ");
        tmp = tmp->snext;
    }
    printf("}");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *tmp;

    if (ht == NULL)
        return;
    tmp = ht->stail;
    printf("{");
    while (tmp != NULL)
    {
        printf("'%s': '%s'", tmp->key, tmp->value);
        if (tmp->sprev != NULL)
            printf(", ");
        tmp = tmp->sprev;
    }
    printf("}");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *tmp, *tmp2;

    if (ht == NULL)
        return;
    for (i = 0; i < ht->size; i++)
    {
        tmp = ht->array[i];
        while (tmp != NULL)
        {
            tmp2 = tmp->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
            tmp = tmp2;
        }
    }
    free(ht->array);
    free(ht);
}
