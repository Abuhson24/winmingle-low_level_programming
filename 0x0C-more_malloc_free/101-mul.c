#include "main.h"
#include <stdlib.h>
#include <unistd.h>

int is_digit(char *str);
int _strlen(char *str);
char *add_strings(char *s1, char *s2);
void print_error(void);

int is_digit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	while (str[len] != '\0')
		len++;
	return (len);
}

char *add_strings(char *s1, char *s2)
{
	int len1, len2, max_len, carry, i, j, k;
	char *result;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	max_len = (len1 > len2 ? len1 : len2) + 2;

	result = malloc(max_len * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < max_len; i++)
		result[i] = '0';
	result[max_len - 1] = '\0';

	carry = 0;
	k = max_len - 2;
	i = len1 - 1;
	j = len2 - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0)
			sum += s1[i--] - '0';
		if (j >= 0)
			sum += s2[j--] - '0';
		result[k--] = (sum % 10) + '0';
		carry = sum / 10;
	}

	while (result[0] == '0' && result[1] != '\0')
	{
		for (i = 0; result[i] != '\0'; i++)
			result[i] = result[i + 1];
	}

	return (result);
}

char *multiply(char *num1, char *num2)
{
	char *result, *temp, *partial;
	int len1, len2, i, j, carry, digit;
	int result_len;

	if (num1[0] == '0' || num2[0] == '0')
	{
		result = malloc(2 * sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result_len = len1 + len2;
	result = malloc((result_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i <= result_len; i++)
		result[i] = '0';
	result[result_len] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		partial = malloc((len2 + 2) * sizeof(char));
		if (partial == NULL)
		{
			free(result);
			return (NULL);
		}

		for (j = 0; j <= len2 + 1; j++)
			partial[j] = '0';
		partial[len2 + 1] = '\0';

		for (j = len2 - 1; j >= 0; j--)
		{
			digit = (num1[i] - '0') * (num2[j] - '0') + carry;
			partial[j + 1] = (digit % 10) + '0';
			carry = digit / 10;
		}
		partial[0] = carry + '0';

		temp = add_strings(result, partial);
		if (temp == NULL)
		{
			free(partial);
			free(result);
			return (NULL);
		}
		for (j = 0; temp[j] != '\0'; j++)
			result[j] = temp[j];
		result[j] = '\0';
		free(partial);
		free(temp);
	}

	while (result[0] == '0' && result[1] != '\0')
	{
		for (i = 0; result[i] != '\0'; i++)
			result[i] = result[i + 1];
	}

	return (result);
}

void print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(98);
}

int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3)
		print_error();

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();

	result = multiply(argv[1], argv[2]);
	if (result == NULL)
		print_error();

	write(STDOUT_FILENO, result, _strlen(result));
	write(STDOUT_FILENO, "\n", 1);
	free(result);

	return (0);
}
