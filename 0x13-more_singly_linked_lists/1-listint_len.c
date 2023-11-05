#include "lists.h"

/**
 * listint_len - This returns number of elements in a linked lists
 * @h: contains linked list of type listint_t to traverse
 *
 * Return: number of nodes on success and NULL on fialure
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}
