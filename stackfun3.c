#include "monty.h"
/**
 * sub - sub the top two elements of the stack.
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *del;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	del = *stack;
	((*stack)->next)->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(del);

}

/**
 * divide - divide the top two elements of the stack.
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *del;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	del = *stack;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n /= (*stack)->n;
	*stack = (*stack)->next;
	free(del);

}

/**
 * mul - mul the top two elements of the stack.
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *del;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	del = *stack;
	((*stack)->next)->n *= (*stack)->n;
	*stack = (*stack)->next;
	free(del);

}

/**
 * mod - divide the top two elements of the stack.
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *del;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	del = *stack;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n %= (*stack)->n;
	*stack = (*stack)->next;
	free(del);

}
