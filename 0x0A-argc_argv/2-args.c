#include "main.h"
#include <stdio.h>

/**
 * main - prints all command-line arguments passed to the program
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i;
	
	/* Loop through all arguments from index 0 to argc-1 */
	for (i = 0; i < argc; i++)
	{
		/* Print each argument followed by a newline */
		printf("%s\n", argv[i]);
	}
	
	return (0);
}
