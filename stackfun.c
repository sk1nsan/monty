#include "monty.h"
extern char **LINEV;

/**
 * push - push into stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (LINEV[1] == NULL || !_isnumber(LINEV[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->n = _atoi(LINEV[1]);
	*stack = new;
}

/**
 * pall - prints stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr = *stack;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * free_stack - free stack
 *
 * @stack: stack
 *
 * Return: void
*/

void free_stack(stack_t **stack)
{
	stack_t *del;

	if (stack == NULL)
		return;
	if (*stack == NULL)
	{
		free(*stack);
		return;
	}
	while (*stack != NULL)
	{
		if ((*stack)->next == NULL)
		{
			free(*stack);
			*stack = NULL;
			return;
		}
		del = *stack;
		*stack = (*stack)->next;
		free(del);
	}
}
