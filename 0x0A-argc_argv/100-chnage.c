#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins needed to make change
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: 0 on success, 1 on error (incorrect argument count)
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;
	int i;
	
	/* Array of coin denominations in descending order */
	int denominations[] = {25, 10, 5, 2, 1};
	int num_denominations = 5;
	
	/* Check if exactly one argument (plus program name) is passed */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	
	/* Convert the argument to an integer */
	cents = atoi(argv[1]);
	
	/* If cents is negative, print 0 */
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}
	
	/* Greedy algorithm: use largest coins first */
	for (i = 0; i < num_denominations; i++)
	{
		/* Add the number of coins of current denomination */
		coins += cents / denominations[i];
		
		/* Update remaining cents */
		cents = cents % denominations[i];
		
		/* If no cents left, break early */
		if (cents == 0)
			break;
	}
	
	/* Print the minimum number of coins */
	printf("%d\n", coins);
	
	return (0);
}
