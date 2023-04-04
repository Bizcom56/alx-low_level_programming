#include "lists.h"

/**
 * listint_len - returns the number of elements in
 * a linked list.
 * @head: defines head of a list.
 *
 * Return: numbers of nodes.
 */
size_t listint_len(const listint_t *head)
{
	size_t num_nodes = 0;

	while (head != NULL)
	{
		head = head->next;
		num_nodes++;
	}
	return (num_nodes);
}

