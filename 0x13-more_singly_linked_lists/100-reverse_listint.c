#include "lists.h"

/**
 * Reverse_listint - reverses our linked list
 * @head: is the pointer to first node in the list
 *
 * Return: pointer to the first node in our new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}
