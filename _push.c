#include "monty.h"

/**
 * _push - pushes an item on to the stack, using LIFO
 * @stack: pointer to a pointer that points to the top of the stack
 * @line_number: line number (data, stored in stack), gotten from a given file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_item = NULL;
	int data = (int)line_number;

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		write(2, "Error: malloc failed\n", 22);
		free(new_item);
		free_stack();
		exit(EXIT_FAILURE);
	}
	new_item->n = data;
	new_item->prev = NULL;
	if (*stack == NULL)
	{
		top = new_item;
		new_item->next = NULL;
	}
	else
	{
		top->prev = (struct stack_s *)new_item;
		new_item->next = (struct stack_s *)top;
		top = new_item;
	}
}

/**
  * is_push - checks whether an opcode is push or not
  * @opcode: opcode to be checked
  * @arg: the line number argument, obtained from a given file
  * Return: 1, if a given opcode is push, 0 otherwise
  */
int is_push(char *opcode, char *arg)
{
	int is_psh = strcmp(opcode, "push") == 0;
	int is_nm = 0;

	if (arg == NULL)
		return (0);
	is_nm = ((atoi(arg) > 0) || ((atoi(arg) == 0) && (strcmp(arg, "0") == 0)));
	if (is_psh && is_nm)
		return (1);
	return (0);
}

/**
 * push_error - handles push related error
 * @line_number: the line in a file where there is bad syntax
 */
void push_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 28);

	sprintf(error_msg, "L%i: usage: push integer\n", line_number);
	write(2,  error_msg, strlen(error_msg));
	free(error_msg);
	free_stack();
	exit(EXIT_FAILURE);
}

