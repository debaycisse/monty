#include "monty.h"

/**
 * mul_stack - multiplies two topmost items in a given stack
 * @stack: pointer to a pointer that points to the top item in a stack
 * @line_number: line number in a file, where error occurs
 *
 * Description: multiplies two topmost items of stack with one another,
 * saves the result in the second item and remove the first item
 */
void mul_stack(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *next = NULL;

	top = *stack;
	if (stack_len(stack) > 2)
	{
		sum = top->n;
		next = (stack_t *)top->next;
		sum *= next->n;
		next->n = sum;
		free(top);
		next->prev = NULL;
		top = next;
	}
	else
		mul_error((int) line_number);
}

/**
 * mul_error - handles error, related to multiplying two stack items
 * @line_number: the line number, used in tracking where error occurs
 */
void mul_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 35);

	sprintf(error_msg, "L%i: can't mul, stack too short\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * is_mul - checks if the given opcode is equal to mul
 * @opcode: the opcode to be checked
 * Return: 1, if the given opcode is equal to mul, 0 otherwise
 */
int is_mul(char *opcode)
{
	if (strcmp(opcode, "mul") == 0)
		return (1);
	return (0);
}

