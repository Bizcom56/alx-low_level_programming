#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) of a doubly linked list
 *
 * @head: Head of the list
 * Return: Sum of the data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	/* Check if the list is empty (head is NULL) */
	if (head == NULL)
		return (0);

	/* Traverse to the first node (if not already) */
	while (head->prev != NULL)
	head = head->prev;

    /* Traverse the list and accumulate the sum of data elements */
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

