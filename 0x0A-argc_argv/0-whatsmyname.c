#include "main.h"
#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	/* argc is not needed for this task, but we keep the parameter */
	(void)argc;  /* Explicitly cast to void to avoid compiler warning */
	
	/* Print the program name (argv[0] contains it) */
	printf("%s\n", argv[0]);
	
	return (0);
}
