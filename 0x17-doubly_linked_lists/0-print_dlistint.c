#include "lists.h"

/**
 * print_dlistint - Display all elements within a doubly linked list
 *
 * This function prints the elements stored in a dlistint_t type linked list.
 *
 * @h: The head of the doubly linked list.
 * Return: The number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	int count;

	count = 0;

	if (h == NULL)
		return (count);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}
