#include <stdlib.h>
#include "lists.h"

/**
 * release_list - releases a linked list
 * @list: list_t list to be released
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}

