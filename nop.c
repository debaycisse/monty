#include "monty.h"

/**
 * nop - no opcode. This does nothing
 * @stack: pointer to a pointer that points at the item at the top of a stack
 * @line_number: line number of a given file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	top = *stack;
	(void)line_number;
}

/**
 * is_nop - checks if the given opcode is equal to nop
 * @opcode: the opcode to be checked
 * Return: 1, if the opcode is equal to nop, 0 otherwise
 */
int is_nop(char *opcode)
{
	if (strcmp(opcode, "nop") == 0)
		return (1);
	return (0);
}

