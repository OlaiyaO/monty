#include "monty.h"

/**
 * execute_opcode - executes the Monty script opcode
 * @line_content: line content from the Monty script
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 * @monty_file: pointer to the Monty script file
 * Return: 0 on success, 1 on failure
 */

int execute_opcode(
		char *line_content,
		stack_t **stack,
		unsigned int line_number,
		FILE *monty_file)
{
	instruction_t opcode_table[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	unsigned int i;
	char *opcode;

	opcode = strtok(line_content, " \n\t");

	if (opcode && opcode[0] == '#')
		return (0);

	appstate.arg = strtok(NULL, " \n\t");

	for (i = 0; opcode_table[i].opcode && opcode; i++)
	{
		if (strcmp(opcode, opcode_table[i].opcode) == 0)
		{
			opcode_table[i].f(stack, line_number);
			return (0);
		}
	}

	if (opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(monty_file);
		free(line_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
