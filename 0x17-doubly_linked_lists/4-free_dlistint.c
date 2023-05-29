#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list of type dlistint_t.
 *
 * @head: Pointer to the head of the list.
 *
 * Description: This function frees each node in a doubly linked list.
 *              It starts from the head node and iteratively frees each
 *              node until the end of the list is reached. The memory
 *              occupied by each node is released using the free() function.
 *              The head pointer is set to NULL at the end, indicating an
 *              empty list. This function has a time complexity of O(n),
 *              where n is the number of nodes in the list.
 *
 * Return: None.
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *tmp;

    /* Check if the list is not empty */
    if (head != NULL)
    {
        /* Traverse to the first node (if not already) */
        while (head->prev != NULL)
            head = head->prev;
    }

    /* Free each node of the list */
    while ((tmp = head) != NULL)
    {
        /* Update head to the next node */
        head = head->next;

        /* Free the current node */
        free(tmp);
    }
}

