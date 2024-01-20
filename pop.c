#include "monty.h"

/**
 * pop - removes the item at the top of the stack
 * @stack: pointer to a pointer that points at the top of the stack
 * @line_number: line number of the current line of given file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	(void)line_number;
	top = *stack;
	if (top != NULL)
	{
		next = (stack_t *)top->next;
		if (next != NULL)
			next->prev = NULL;
		free(top);
		top = next;
	}
	else
		pop_error((int) line_number);
}

/**
 * pop_error - handles pop opcode related error
 * @line_number: the line number of the line where error occurs
 */
void pop_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 32);

	sprintf(error_msg, "L%i: can't pop an empty stack\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	exit(EXIT_FAILURE);
}

/**
 * is_pop - checks if the given opcode is pop
 * @opcode: the opcode to be checked
 * Return: 1, if a given opcode is pop, 0 otherwise
 */
int is_pop(char *opcode)
{
	if (strcmp(opcode, "pop") == 0)
		return (1);
	return (0);
}
