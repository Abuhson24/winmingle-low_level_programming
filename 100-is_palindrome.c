#include "main.h"

/**
 * get_length - Helper function to get the length of a string recursively
 * @s: Pointer to the string
 *
 * Return: Length of the string
 */
int get_length(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + get_length(s + 1));
}

/**
 * check_palindrome - Helper function to check if a string is a palindrome
 * @s: Pointer to the string
 * @start: Starting index
 * @end: Ending index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
	{
		return (1);
	}
	if (s[start] != s[end])
	{
		return (0);
	}
	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - Returns 1 if a string is a palindrome and 0 if not
 * @s: Pointer to the string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int length = get_length(s);
	
	if (length <= 1)
	{
		return (1);
	}
	return (check_palindrome(s, 0, length - 1));
}
