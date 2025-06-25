#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string
 *
 * Description: The '*' character in s2 can match any characters in s1.
 *
 * Return: 1
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (*(s2 + 1) == '\0')
			return (1);

		if (wildcmp(s1, s2 + 1))
			return (1);

		if (*s1 != '\0')
			return (wildcmp(s1 + 1, s2));

		return (0);
	}

	if (*s1 == '\0')
		return (0);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
