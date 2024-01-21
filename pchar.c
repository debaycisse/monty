#include "monty.h"

/**
 * pchar - prints the character ascii equivalent of a val
 * @stack: pointer to a pointer that points at the top of a stack
 * @line_number: line number of am opcode with bad syntax
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int character = 0;

	top = *stack;
	if (top != NULL)
	{
		character = top->n;
		if (character >= 32 && character <= 126)
			printf("%c\n", (char)character);
		else
			out_of_range_error((int) line_number);
	}
	else
		empty_stack_error((int) line_number);
}

/**
 * out_of_range_error - handles non-existing ascii value
 * @line_number: line number of am opcode with bad syntax
 */
void out_of_range_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 40);

	sprintf(error_msg, "L%i: can't pchar, value out of range\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * empty_stack_error - handles empty stack error
 * @line_number: line number of am opcode with bad syntax
 */
void empty_stack_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 32);

	sprintf(error_msg, "L%i: can't pchar, stack empty\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * is_pchar - checks if the opcode is equal to pchar
 * @opcode: the opcode to be checked
 * Return: 1, if the opcode is equal to pchar, else 0 is returned
 */
int is_pchar(char *opcode)
{
	if (strcmp(opcode, "pchar") == 0)
		return (1);
	return (0);
}

