#include "monty.h"

/**
 * _push - adds a node to the stack or queue
 * @head: stack head or the topmost of the stack
 * @counter: the number of lines
 * Return: nothing to return
 */
void _push(stack_t **head, unsigned int counter)
{
	int number, i = 0;

	if (!appstate.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(appstate.file);
		free(appstate.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (appstate.arg[0] == '-')
		i++;
	while (appstate.arg[i] != '\0')
	{
		if (appstate.arg[i] < '0' || appstate.arg[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(appstate.file);
			free(appstate.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	number = atoi(appstate.arg);

	if (appstate.mode_flag < 0)
		enqueue(head, number);
	else
		addnode(head, number);
}
