#include "monty.h"

/**
 * _mod - Computes the rest of the division of the second
 * top element by the top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	_pop(stack, line_number);
}
