#include "lists.h"

/**
 * add_dnodeint_end - Appends a new node to the tail
 *                    of a dlistint_t list.
 *
 * This function adds a new node containing the given
 * value 'n' to the end of the doubly linked list pointed
 * to by 'head'. If the list is empty, the new node becomes
 * the head.
 *
 * @head: Pointer to the head of the list.
 * @n: Value of the element to be added.
 * Return: Address of the newly added element.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h = *head;
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (h != NULL)
	{
		while (h->next != NULL)
		{
			h = h->next;
		}
		h->next = new_node;
	}
	else
	{
	*head = new_node;
	}

	new_node->prev = h;

	return (new_node);
}

