#include "monty.h"

/**
 * pop - removes element on the top of the stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *del = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	free(del);

}
