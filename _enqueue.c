#include "monty.h"

/**
 * enqueue - adds a new node to the end of the linked list (queue)
 * @head: pointer to the head of the queue
 * @data: integer to be stored in the new node
 */
void enqueue(stack_t **head, int data)
{
	stack_t *new_node = malloc(sizeof(stack_t)), *last;

	if (!new_node)
		exit(EXIT_FAILURE);

	new_node->n = data;
	new_node->next = NULL;

	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	last = *head;

	while (last->next)
	{
		last = last->next;
	}

	last->next = new_node;
	new_node->prev = last;
}
