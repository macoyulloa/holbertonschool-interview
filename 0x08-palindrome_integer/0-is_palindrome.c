#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - check if an int is palindrome
 * @n: the integer to check
 * Return: 1 if n is palindrome, otherwise 0
**/
int is_palindrome(unsigned long n)
{
	unsigned long reversed, copyN, tmp;

	reversed = 0;
	tmp = 0;
	copyN = n;

	while (n != 0)
	{
		tmp = n % 10;
		reversed = reversed * 10 + tmp;
		n /= 10;
	}

	if (copyN == reversed)
		return (1);
	return (0);
}
