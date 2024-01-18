#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
 */
void _swap(stack_t **head, unsigned int line_number)
{
	int temp;
	stack_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
