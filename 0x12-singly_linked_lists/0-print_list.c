#include <stdio.h>
#include "lists.h"

/**
 * display_list - displays all elements of a linked list
 * @list: pointer to the list_t list to display
 *
 * Return: the number of nodes displayed
 */
size_t display_list(const list_t *list)
{
	size_t count = 0;

	while (list)
	{
		if (!list->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", list->len, list->str);
		list = list->next;
		count++;
	}

	return (count);
}

