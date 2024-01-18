#include "monty.h"

appstate_t appstate = {NULL, NULL, NULL, 0};
/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char *argv[])
{
	char *line_content = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	FILE *monty_file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	appstate.file = monty_file;

	while ((read = getline(&appstate.content, &len, monty_file)) != -1)
	{
		line_number++;
		line_content = strtok(appstate.content, "\n");
		if (line_content && *line_content != '\0')
		{
			if (execute_opcode(line_content, &stack, line_number, monty_file) != 0)
			{
				free_stack(stack);
				return (EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
	fclose(monty_file);
	free(appstate.content);

	return (EXIT_SUCCESS);
}
