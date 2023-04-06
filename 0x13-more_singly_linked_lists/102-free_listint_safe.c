#include "lists.h"

/**
 * free_listp2 - frees a linked list
 * @head: head of a list.
 *
 * Return: no return.
 */
void free_listp2(listp_t **head)
{
	listp_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

/**
 * free_listint_safe - frees a linked list.
 * @h: head of a list.
 *
 * Return: size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t num_nodes = 0;
	listp_t *hptr = NULL, *new = NULL;
	listint_t *current = NULL;

	while (*h != NULL)
	{
		/* Create a new node and add it to the head of the tracking list */
		new = malloc(sizeof(listp_t));
		if (new == NULL)
			exit(98);

		new->p = (void *)*h;
		new->next = hptr;
		hptr = new;

		/* Check for a loop by traversing the tracking list */
		for (listp_t *tmp = hptr; tmp != NULL; tmp = tmp->next)
		{
			if (*h == tmp->p)
			{
				/* Loop detected, free the tracking list and exit */
				free_listp2(&hptr);
				*h = NULL;
				return (num_nodes);
			}
		}

		/* No loop detected, free the currentent node and move to the next */
		current = *h;
		*h = (*h)->next;
		free(current);
		num_nodes++;
	}

	/* All nodes have been freed, free the tracking list and exit */
	free_listp2(&hptr);
	return (num_nodes);
}
