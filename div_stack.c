#include "monty.h"

/**
 * div_stack - divides two topmost items in a given stack
 * @stack: pointer to a pointer that points to the top item in a stack
 * @line_number: line number in a file, where error occurs
 *
 * Description: divides topmost two element by one another,
 * saves the result in the second item and remove the first item
 * from the stack
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	int first_value = 0, second_value = 0;
	stack_t *next = NULL;

	top = *stack;
	if (stack_len(stack) > 2)
	{
		first_value = top->n;
		next = (stack_t *)top->next;
		second_value = next->n;
		if ((first_value == 0) || (second_value == 0))
			div_by_zero_error((int) line_number);
		if (first_value > second_value)
		{
			first_value /= second_value;
			next->n = first_value;
		}
		else
		{
			second_value /= first_value;
			next->n = second_value;
		}
		free(top);
		next->prev = NULL;
		top = next;
	}
	else
		div_error((int) line_number);
}

/**
 * div_error - handles error, related to dividing two topmost stack items
 * @line_number: the line number, used in tracking where error occurs
 */
void div_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 35);

	sprintf(error_msg, "L%i: can't div, stack too short\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * div_by_zero_error - handles error, related to division by zero
 * @line_number: the line number, used in tracking where error occurs
 */
void div_by_zero_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 25);

	sprintf(error_msg, "L%i: division by zero\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * is_div - checks if the given opcode is equal to sub
 * @opcode: the opcode to be checked
 * Return: 1, if the given opcode is equal to sub, 0 otherwise
 */
int is_div(char *opcode)
{
	if (strcmp(opcode, "div") == 0)
		return (1);
	return (0);
}

