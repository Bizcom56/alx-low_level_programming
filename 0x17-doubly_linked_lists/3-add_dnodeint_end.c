#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 * @head: Pointer to the head of the list
 * @n: Value of the new node
 * Return: Address of the new node, or NULL on failure
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    /*  Allocate memory for the new node */
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
		if (new_node == NULL)
			return (NULL);

    /* Set the value and pointers of the new node */
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	/* If the list is empty, make the new node the head */
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		/* Traverse to the last node */
		dlistint_t *current = *head;
			while (current->next != NULL)
				current = current->next;

		/* Append the new node to the end of the list */
	current->next = new_node;
		new_node->prev = current;
	}

    /* Return the address of the new node */
	return (new_node);
}

