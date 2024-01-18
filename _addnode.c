#include "monty.h"

/**
 * addnode - adds a new node to the top of the linked list (stack)
 * @head: pointer to the head of the stack
 * @data: integer to be stored in the new node
 */

void addnode(stack_t **head, int data)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
		exit(EXIT_FAILURE);

	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;
}
