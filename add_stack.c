#include "monty.h"

/**
 * add_stack - adds two topmost items together in a given stack
 * @stack: pointer to a pointer that points to the top item in a stack
 * @line_number: line number in a file, where error occurs
 *
 * Description: adds two topmost items of stack together and save the result
 * in the second item and remove the first item
 */
void add_stack(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *next = NULL;

	top = *stack;
	if (stack_len(stack) > 2)
	{
		sum += top->n;
		next = (stack_t *)top->next;
		sum += next->n;
		next->n = sum;
		free(top);
		next->prev = NULL;
		top = next;
	}
	else
		add_error((int) line_number);
}

/**
 * add_error - handles error, related to adding two stack items
 * @line_number: the line number, used in tracking where error occurs
 */
void add_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 35);

	sprintf(error_msg, "L%i: can't add, stack too short\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * is_add - checks if the given opcode is equal to add
 * @opcode: the opcode to be checked
 * Return: 1, if the given opcode is equal to add, 0 otherwise
 */
int is_add(char *opcode)
{
	if (strcmp(opcode, "add") == 0)
		return (1);
	return (0);
}

