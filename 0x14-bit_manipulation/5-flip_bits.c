#include "main.h"

/**
 * flip_bits - Calculates the number of
 * differing bits between two numbers.
 * @num1: number one.
 * @num2: number two.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	unsigned int nbits;

	for (nbits = 0; num1 || num2; num1 >>= 1, num2 >>= 1)
	{
		if ((num1 & 1) != (num2 & 1))
			nbits++;
	}

	return (nbits);
}

