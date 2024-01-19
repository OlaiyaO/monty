#include "monty.h"

/**
 * _pstr - Prints the string starting at the top of the stack, then a new line.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL &&
			current->n != 0 &&
			current->n >= 0 &&
			current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
