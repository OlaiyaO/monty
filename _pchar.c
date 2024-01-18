#include "monty.h"

/**
 * _pchar - Prints the char at the top of the stack, followed by a new line.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(ascii_value);
	putchar('\n');
}
