#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers passed as command-line arguments
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: 0 on success, 1 on error (invalid number of arguments)
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	
	/* Check if exactly two arguments (plus program name) are passed */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	
	/* Convert the string arguments to integers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	
	/* Calculate the product */
	result = num1 * num2;
	
	/* Print the result */
	printf("%d\n", result);
	
	return (0);
}
