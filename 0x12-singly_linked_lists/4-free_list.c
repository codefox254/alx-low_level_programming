#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Releases a linked list.
 * @head: Pointer to the list_t list to be released.
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