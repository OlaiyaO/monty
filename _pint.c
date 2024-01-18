#include "monty.h"

/**
 * _pint - Prints the value at the top of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */

void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
