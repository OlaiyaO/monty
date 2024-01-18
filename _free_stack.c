#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the head.
 */

void free_stack(stack_t *head)
{
	stack_t *current = head, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
