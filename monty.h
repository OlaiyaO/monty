#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct appstate - Represents the dynamic state of the application.
 * @arg: Argument value parsed from the Monty script.
 * @file: Pointer to the Monty script file.
 * @content: Content of the current script line.
 * @mode_flag: Flag for stack or queue mode.
 * Description: Encapsulates essential variables for runtime application state.
 */
typedef struct appstate_s
{
	char *arg;
	FILE *file;
	char *content;
	int mode_flag;
} appstate_t;
extern appstate_t appstate;

int execute_opcode(
		char *line_content,
		stack_t **stack,
		unsigned int line_number,
		FILE *monty_file);

void free_stack(stack_t *head);
void addnode(stack_t **head, int data);
void enqueue(stack_t **head, int data);
void _stack(stack_t **head, unsigned int counter);
void _queue(stack_t **head, unsigned int counter);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
