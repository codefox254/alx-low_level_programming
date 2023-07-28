#include <stdlib.h>
#include "lists.h"

/**
 * release_list - releases a linked list
 * @list: list_t list to be released
 */
void release_list(list_t *list)
{
	list_t *current;

	while (list)
	{
		current = list->next;
		free(list->str);
		free(list);
		list = current;
	}
}

