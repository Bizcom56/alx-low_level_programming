#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to the binary number string.
 *
 * Return: Unsigned int converted from binary.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ui = 0;
	int len = 0, base_two = 1;

	if (b == NULL)
		return (0);

	/* Calculate the length of the binary number string */
	while (b[len])
		len++;

	len--;

	/* Convert binary string to unsigned int */
	while (len >= 0)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		if (b[len] == '1')
			ui += base_two;

		base_two *= 2;
		len--;
	}

	return (ui);
}

