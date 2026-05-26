#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_digit_string - checks if a string contains only digits
 * @str: string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit_string(char *str)
{
	int i = 0;
	
	/* Loop through each character in the string */
	while (str[i] != '\0')
	{
		/* If character is not a digit, return 0 */
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	
	return (1);
}

/**
 * main - adds positive numbers passed as command-line arguments
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: 0 on success, 1 on error (non-digit found)
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;
	
	/* Loop through all arguments (starting from index 1, skip program name) */
	for (i = 1; i < argc; i++)
	{
		/* Check if the current argument contains only digits */
		if (!is_digit_string(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		
		/* Convert the valid digit string to integer and add to sum */
		sum += atoi(argv[i]);
	}
	
	/* Print the sum (0 if no arguments provided) */
	printf("%d\n", sum);
	
	return (0);
}
