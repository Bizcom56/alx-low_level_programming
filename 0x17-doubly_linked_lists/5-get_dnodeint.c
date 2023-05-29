#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list
 * @head: Head of the list
 * @index: Index of the nth node
 * Return: Pointer to the nth node, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

    /* Check if the head is NULL (empty list) */
	if (head == NULL)
		return (NULL);

    /* Traverse to the first node (if not already) */
	while (head->prev != NULL)
		head = head->prev;

	/* Traverse the list until the nth node is reached or the end of the list */
	while (count < index && head != NULL)
	{
		head = head->next;
		count++;
	}

	/* Check if the desired index is out of range (beyond the end of the list) */
	if (count < index)
		return (NULL);

	return (head);
}

