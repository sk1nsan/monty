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
	stack_t *del;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	del = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(del);

}

/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = ((*stack)->next)->next;
	temp->next = (*stack);
	(*stack) = temp;

}

/**
 * add - add the top two elements of the stack.
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *del;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	del = *stack;
	((*stack)->next)->n += (*stack)->n;
	*stack = (*stack)->next;
	free(del);

}

/**
 * nop - does nothing
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

}
