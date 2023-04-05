#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to head node
 *
 * Return: data stored in deleted head node, or 0 if list is empty
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	data = temp->n;
	*head = temp->next;
	free(temp);

	return (data);
}
