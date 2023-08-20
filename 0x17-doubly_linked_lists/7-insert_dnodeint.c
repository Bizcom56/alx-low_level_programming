#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 *
 * @h: Pointer to a pointer to the head of the list.
 * @idx: Index of the new node.
 * @n: Value of the new node.
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = NULL;
	dlistint_t *current = *h;
	unsigned int i;

	if (idx == 0)
	{
		new_node = add_dnodeint(h, n);
		return new_node;
	}

	i = 1;
	while (current != NULL && i < idx)
	{
		current = current->next;
		i++;
	}

	if (current != NULL || i == idx)
	{
		new_node = malloc(sizeof(dlistint_t));
		if (new_node != NULL)
		{
			new_node->n = n;

			if (current != NULL)
			{
				new_node->prev = current;
				new_node->next = current->next;

				if (current->next != NULL)
				{
					current->next->prev = new_node;
				}

				current->next = new_node;
            }

			/* If index is at the end or beyond the list length */
			else
			{
				new_node->prev = NULL;
				new_node->next = NULL;
				
				/* Connect the last node's next to the new node*/
				if (*h != NULL)
				{
				dlistint_t *last = *h;
				while (last->next != NULL)
					{
						last = last->next;
                    }
					last->next = new_node;
					new_node->prev = last;
				}

				else
				{

					/* Make the new node the head of the list */
					*h = new_node;
				}
			}
		}
	}

		return (new_node);
}
