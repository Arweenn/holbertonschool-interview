#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"


/**
 * is_palindrome - test if <n> is a palindrome
 * @n: unsigned long int
 * Return: 1 if it's a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int reversed = 0, remainder, original;
	original = n;

	/* reversed integer is stored in reversed variable */
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	/* palindrome if orignal and reversed are equal */
	if (original == reversed)
		return (1);
	else
		return (0);
}
