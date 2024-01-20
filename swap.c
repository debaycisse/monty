#include "monty.h"

/**
 * swap - swaps the top two items in a given stack
 * @stack: pointer to the pointer that point at the top item in a stack
 * @line_number: the number of a line where error occurs in a given file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top = NULL, *prev_top = NULL;

	if (stack_len(stack) >= 2)
	{
		top = *stack;
		prev_top = top;
		new_top = (stack_t *)prev_top->next;
		prev_top->next = new_top->next;
		prev_top->prev = (struct stack_s *)new_top;
		new_top->prev = NULL;
		new_top->next = (struct stack_s *)prev_top;
		top = new_top;
	}
	else
		swap_error((int) line_number);
}

/**
 * swap_error - handles swapping related error
 * @line_number: the line number where error occurs
 */
void swap_error(int line_number)
{
	char *error_msg = malloc(sizeof(char) * 36);

	sprintf(error_msg, "L%i: can't swap, stack too short\n", line_number);
	write(2, error_msg, strlen(error_msg));
	free(error_msg);
	exit(EXIT_FAILURE);
}

/**
 * is_swap - checks if the opcode is swap or not
 * @opcode: the opcode to be checked
 * Return: 1, if opcode is swap, 0 otherwise
 */
int is_swap(char *opcode)
{
	if (strcmp(opcode, "swap") == 0)
		return (1);
	return (0);
}

/**
 * stack_len - calculates the number of items in a stack
 * @stack: pointer to a pointer that points to the top of the stack
 * Return: the total number of items in a stack or 0 if stack is empty
 */
int stack_len(stack_t **stack)
{
	stack_t *current_item = *stack;
	int len = 0;

	while (current_item)
	{
		len++;
		current_item = current_item->next;
	}
	return (len);
}

