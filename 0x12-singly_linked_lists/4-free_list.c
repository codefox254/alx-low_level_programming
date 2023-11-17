#include <stdio.h>
#include <stdlib.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

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

int main(void)
{
    list_t *head = NULL;

    /* Example: Adding elements to the linked list */
    list_t *node1 = malloc(sizeof(list_t));
    node1->str = "Hello";
    node1->len = 5;
    node1->next = NULL;

    list_t *node2 = malloc(sizeof(list_t));
    node2->str = "World";
    node2->len = 5;
    node2->next = NULL;

    list_t *node3 = malloc(sizeof(list_t));
    node3->str = "!";
    node3->len = 1;
    node3->next = NULL;

    head = node1;
    node1->next = node2;
    node2->next = node3;

    /* Printing the linked list */
    print_list(head);

    /* Freeing the allocated memory */
    while (head)
    {
        list_t *temp = head;
        head = head->next;
        free(temp->str);
        free(temp);
    }

    return 0;
}
