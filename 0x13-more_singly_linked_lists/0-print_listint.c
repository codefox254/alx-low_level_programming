#include "lists.h"

/**
 * print_listint - Displays all elements in a linked list
 * @h: Pointer to a linked list of type listint_t
 *
 * Return: Number of nodes in the list 
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}
