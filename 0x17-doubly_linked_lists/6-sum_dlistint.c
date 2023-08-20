#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n)
 *               of a doubly linked list.
 *
 * @head: Head of the list
 * Return: Sum of the data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head != NULL)
	{

		/* Move to the beginning of the list */
		while (head->prev != NULL)
		{
			head = head->prev;
		}

		/* Traverse the list and sum up the values */
		while (head != NULL)
		{
		sum += head->n;
			head = head->next;
		}
	}

	return (sum);
}

