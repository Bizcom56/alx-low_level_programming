#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list and its nodes.
 *
 * This function releases the memory used by each node
 * in the given doubly linked list. It starts from the
 * head of the list and iterates through, freeing each node.
 *
 * @head: Pointer to the head of the list.
 * Return: No return value.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

    /* Move to the beginning of the list if not there already */
	while (head != NULL && head->prev != NULL)
	head = head->prev;

    /* Iterate through the list and free each node */
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
	free(tmp);
	}
}

