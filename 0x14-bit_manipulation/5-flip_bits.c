#include "main.h"

/**
 * flip_bits - Calculates the number of differing bits between two numbers.
 *
 * This function computes the count of bits that need to be flipped to transform
 * one number into another.
 *
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The count of differing bits.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits;

	for (nbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			nbits++;
	}

	return (nbits);
}
