#include "main.h"

/**
 * binary_to_un_intnt - converts a binary number to an unsigned int.
 * @b: binary string to convert
 *
 * Return: unsigned integer representation of the binary string
 */
unsigned int binary_to_un_intnt(const char *b)
{
	unsigned int un_int;
	int length, base_two;

	if (!b)
		return (0);

	un_int = 0;

	for (length = 0; b[length] != '\0'; length++);

	for (length--, base_two = 1; length >= 0; length--, base_two *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}

		if (b[length] & 1)
		{
			un_int += base_two;
		}
	}

	return (un_int);
}
