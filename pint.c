#include "monty.h"

/**
 * pint - prints only the value of item at the top of the stack
 * @stack: pointer to a pointer that points at the top
 * @line_number: line number (data), obtained from the given file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	top = *stack;
	if (top != NULL)
		printf("%i\n", top->n);
	else
		pint_error((int) line_number);
}

/**
 * pint_error - handles pint opcode's related error
 * @line_number: line number in a given file, where error occurs
 */
void pint_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 30);

	sprintf(error_msg, "L%i: can't pint, empty stack\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	exit(EXIT_FAILURE);
}

/**
 * is_pint - checks if the given opcode is pint
 * @opcode: opcode to be checked
 * Return: 1, if a given opcode is pint, 0 otherwise
 */
int is_pint(char *opcode)
{
	if (strcmp(opcode, "pint") == 0)
		return (1);
	return (0);
}

