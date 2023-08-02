#include <stdio.h>
#include "lists.h"

/**
 * print_list - Displays all elements of a linked list.
 * @h: Pointer to the list_t list to display.
 *
 * Return: The number of nodes displayed.
 */
size_t print_list(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		s++;
	}

	return (s);
}

