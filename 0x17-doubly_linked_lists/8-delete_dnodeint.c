#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node
 * at a given index of a dlistint_t linked list.
 *
 * @head: Pointer to a pointer to the head of the list.
 * @index: Index of the node to be deleted.
 * Return: 1 if deletion succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	if (*head == NULL)
		/* List is empty, deletion failed*/
		return (-1);

	dlistint_t *current = *head;
	dlistint_t *previous = NULL;
	unsigned int i = 0;

	/* Traverse to the beginning of the list */
	while (current->prev != NULL)
		current = current->prev;

	/* Traverse the list to find the node at the specified index */
	while (current != NULL && i < index)
	{
		previous = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
	/* Index out of bounds, deletion failed */
		return (-1);

	/* Adjust pointers to bypass the node to be deleted */
	if (previous != NULL)
		previous->next = current->next;
	else
		/* Removing the head node */
		*head = current->next;

	if (current->next != NULL)
		current->next->prev = previous;

	/* Free the memory of the node to be deleted */
	free(current);

	/* Deletion succeeded */
	return (1);
}

