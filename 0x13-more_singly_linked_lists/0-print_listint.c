#include "lists.h"

/**
 * print_listint - prints all the elements of a list.
 * @head: head of a list.
 *
 * Return: numbers of nodes.
 */
size_t print_listint(const listint_t *head)
{
	size_t num_nodes = 0;

	while (h != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		num_nodes++;
	}
	return (num_nodes);
}
