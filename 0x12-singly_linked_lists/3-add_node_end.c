#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * append_node - adds a new node at the end of a linked list
 * @list: double pointer to the list_t list
 * @data: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *append_node(list_t **list, const char *data)
{
	list_t *new_node;
	list_t *current = *list;
	unsigned int length = 0;

	while (data[length])
		length++;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(data);
	new_node->len = length;
	new_node->next = NULL;

	if (*list == NULL)
	{
		*list = new_node;
		return (new_node);
	}

	while (current->next)
		current = current->next;

	current->next = new_node;

	return (new_node);
}

