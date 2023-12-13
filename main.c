#include "monty.h"
/**
 * main - entry point
 *
 * @argc: number of args
 * @argv: argument vector
 *
 * Return: 0 succ
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_monty(argv[1]);
	return (0);
}
