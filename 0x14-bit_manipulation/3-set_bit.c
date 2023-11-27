#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a specified index.
 *
 * @n: Pointer to an unsigned long int.
 * @index: The index of the bit to set.
 *
 * Return: 1 if successful, -1 if not.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	m = 1 << index;
	*n = (*n | m);

	return (1);
}

