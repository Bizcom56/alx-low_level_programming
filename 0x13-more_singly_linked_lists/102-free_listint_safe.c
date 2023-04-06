#include "lists.h"

/**
 * free_listint2 - frees a linked list and sets the head to NULL
 * @head: pointer to head of a list
 *
 * Return: no return
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
	{
		return;
	}

	while (*head != NULL)
	{
		current = *head;
		*head = current->next;
		free(current)
	}

	*head = (NULL);
}
