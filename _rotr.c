#include "monty.h"

/**
 * _rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *second;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		current = *stack;
		second = NULL;

		while (current->next != NULL)
		{
			second = current;
			current = current->next;
		}

		second->next = NULL;
		current->next = *stack;
		(*stack)->prev = current;
		*stack = current;
	}
}
