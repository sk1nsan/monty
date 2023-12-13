#define _POSIX_C_SOURCE 200809L
#include "monty.h"

char **LINEV;

/**
 * read_monty - main function
 *
 * @filename: monty file
 *
 * Return: void
*/
void read_monty(char *filename)
{
	stack_t *stack = NULL;
	FILE *fp = fopen(filename, "r");
	char *line = NULL;
	int stat;
	unsigned int linenumber = 0;
	size_t n;

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	stat = getline(&line, &n, fp);
	while (stat != -1)
	{
		linenumber++;
		LINEV = arg_vector(line);
		check_command(LINEV, linenumber, &stack);
		free(line);
		line = NULL;
		stat = getline(&line, &n, fp);
		clean_args(LINEV);
	}
	free(line);
	free_stack(&stack);
	fclose(fp);
}

/**
 * clean_args - free vector
 *
 * @LINEV: vector to be freed
 *
 * Return: void
*/

void clean_args(char **LINEV)
{
	int i;

	for (i = 0; LINEV[i]; i++)
		free(LINEV[i]);
	free(LINEV);
}

/**
 * get_opcode - get opcode
 *
 * @opcode: opcode
 * @line_number: line number
 * @stack: stack
 *
 * Return: 1 if opcode exists
 * 0 otherwise
*/
int get_opcode(char *opcode, unsigned int line_number, stack_t **stack)
{
	instruction_t instruction_arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruction_arr[i].opcode; i++)
	{
		if (_strcmp(instruction_arr[i].opcode, opcode) == 0)
		{
			instruction_arr[i].f(stack, line_number);
			return (1);
		}
	}
	return (0);
}

/**
 * check_command - check if command exits
 *
 * @LINEV: vector
 * @line_number: line number
 * @stack: stack
 *
 * Return: void
*/
void check_command(char **LINEV, unsigned int line_number, stack_t **stack)
{
	if (LINEV[0] && LINEV[0][0] == '#')
		return;
	if (LINEV[0] && !get_opcode(LINEV[0], line_number, stack))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, LINEV[0]);
		exit(EXIT_FAILURE);
	}

}
