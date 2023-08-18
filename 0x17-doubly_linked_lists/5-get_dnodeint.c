#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 *
 * This function retrieves the node located at the specified index 'index'
 * within the doubly linked list pointed to by 'head'. The index is zero-based,
 * meaning the first node has index 0, the second has index 1, and so on.
 *
 * @head: Pointer to the head of the list.
 * @index: Index of the desired node.
 * Return: Pointer to the nth node, or NULL if not found.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

    /* Move to the beginning of the list if not already there*/
	while (head != NULL && head->prev != NULL)
		head = head->prev;

	/* Traverse the list to find the node at the specified index */
	while (head != NULL)
	{
		if (i == index)
			break;
		head = head->next;
		i++;
	}

	/*Returns the nth node or NULL if not found*/
	return (head);
}

