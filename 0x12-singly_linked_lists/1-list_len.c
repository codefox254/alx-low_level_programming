#include <stdlib.h>
#include "lists.h"

/**
 * count_elements - counts the number of elements in a linked list
 * @list: pointer to the list_t list
 *
 * Return: number of elements in list
 */
size_t count_elements(const list_t *list)
{
	size_t count = 0;

	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

