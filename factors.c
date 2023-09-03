#include <stdio.h>

/**
 * factorize - Factorize a number into two smaller integers.
 * @n: The number to factorize.
 *
 * This function attempts to find a factorization of the input number @n into
 * two smaller integers, @i and @j. It prints the factorization in the format
 * "n=i*j". If no factorization is found, it assumes that the input number is
 * prime and prints it in the format "n=n*1".
 */

void factorize(int n)
{
	int x, y;
	for (x = 2; y <= n / 2; ++x)
	{
		if (n % x == 0)
		{
			y = n / x;
			printf("%d=%d*%d\n", n, x, y);
			return;
		}
	}
	printf("%d is a prime number\n", n);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * This function reads numbers from a file specified in the command-line
 * arguments and calls the factorize function to factorize each number.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
	}

	FILE *file;
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Could not open file %s\n", argv[1]);
		return 1;
	}

	int num;
	while (fscanf(file, "%d", &num) != EOF)
	{
		factorize(num);
	}

	fclose(file);

	return 0;
}
