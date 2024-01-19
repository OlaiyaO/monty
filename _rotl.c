#include "monty.h"

/**
 * _rotl - Rotates the stack to the top.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *current;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		second = (*stack)->next;
		current = *stack;

		while (current->next != NULL)
		{
			current = current->next;
		}

		first->next = NULL;
		current->next = first;
		*stack = second;
		second->prev = NULL;
	}
}
