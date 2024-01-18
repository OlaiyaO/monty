#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */

void _add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;
	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
