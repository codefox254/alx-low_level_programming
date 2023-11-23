#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from n to m
 * @n: First number
 * @m: Second number
 *
 * Return: Number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;
	int i;

	for (i = 63; i >= 0; i--)
	{
		count += (xor_result >> i) & 1;
	}

	return count;
}
