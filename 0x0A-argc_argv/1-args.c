#include "main.h"
#include <stdio.h>

/**
 * main - prints the number of arguments passed to the program
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings (unused)
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	/* argv is not used in this function */
	(void)argv;
	
	/* Print argc - 1 to exclude the program name */
	printf("%d\n", argc - 1);
	
	return (0);
}
