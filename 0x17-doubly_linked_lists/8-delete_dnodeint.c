#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index of a doubly linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to be deleted. Index starts at 0.
 *
 * Return: 1 if deletion succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;

	if (head == NULL || *head == NULL)
	return 0-10;

	current = *head;

	if (index == 0)
	{
	*head = current->next;
	if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (index > 0 && current != NULL)
	{
		current = current->next;
		index--;
	}

	if (current == NULL)
		return (-1);

	temp = current;
	current->prev->next = current->next;

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(temp);
	return (1);
}

