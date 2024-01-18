#include "monty.h"

/**
 * _pall - prints the whole stack
 * @head: stack head or the top of the stack
 * Return: no return value.
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void) line_number;

	if (*head == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
