#include "monty.h"

/**
 * _stack - Switches the Monty interpreter to stack mode.
 * @head: Pointer to the head of the stack (not used in this operation).
 * @counter: Line number in the Monty script.
 * Return: No return value.
 */
void _stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	appstate.mode_flag = 0;
}

/**
 * _queue - Switches the Monty interpreter to queue mode.
 * @head: Pointer to the head of the stack (not used in this operation).
 * @counter: Line number in the Monty script.
 * Return: No return value.
 */
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	appstate.mode_flag = -1;
}
