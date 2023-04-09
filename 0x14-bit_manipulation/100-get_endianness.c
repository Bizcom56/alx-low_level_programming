#include "main.h"

/**
 * a function that returns the number of bits 
 * you would need to flip to get from one number to another.
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int y;
	char *c;

	y = 1;
	c = (char *) &y;

	return ((int)*c);
}
