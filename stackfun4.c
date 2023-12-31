#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (n < 65 || n > 122)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int n;

	(void) line_number;
	while (curr)
	{
		n = curr->n;
		if (n < 1 || n > 127)
			break;
		putchar(n);
		curr = curr->next;

	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top.
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void) line_number;
	if (stack == NULL || *stack == NULL)
		return;
	while (curr)
	{
		if (curr->next == NULL)
			break;
		curr = curr->next;
	}
	curr->next = *stack;
	(*stack)->prev = curr;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(curr->next)->next = NULL;
}

/**
 * rotr - rotates the stack to the top.
 *
 * @stack: stack
 * @line_number: line number
 *
 * Return: void
*/

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void) line_number;
	if (stack == NULL || *stack == NULL)
		return;
	if (curr->next == NULL)
		return;
	while (curr)
	{
		if (curr->next == NULL)
			break;
		curr = curr->next;
	}
	(curr->prev)->next = NULL;
	curr->next = *stack;
	curr->prev = NULL;
	(*stack)->prev = curr;
	*stack = curr;
}
