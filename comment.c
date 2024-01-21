#include "monty.h"

/**
 * comment - handles a comment line
 * @stack: pointer to a pointer that points to the tope of the stack
 * @line_number: line number that tracks which line has bad syntax
 */
void comment(stack_t **stack, unsigned int line_number)
{
	nop(stack, line_number);
}

/**
 * is_comment - checks if the opcode is equal to #
 * @opcode: the opcode to be checked
 * Return: 1, if opcode is equal to #, else 0 is returned
 */
int is_comment(char *opcode)
{
	if (strcmp(opcode, "#") == 0)
		return (1);
	return (0);
}

