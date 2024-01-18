#include "monty.h"

/**
 * _pop - Removes the top element of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;

	if (*head != NULL)
		(*head)->prev = NULL;

	free(temp);
}
