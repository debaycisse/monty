#include "monty.h"

/**
 * _pall - prints all items in a stack
 * @stack: pointer to a pointer that points to the top of the stack
 * @line_number: the line number (data stored in stack) from the given file
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_item = NULL;

	top = *stack;
	current_item = top;
	(void)line_number;
	while (current_item != NULL)
	{
		printf("%i\n", current_item->n);
		current_item = current_item->next;
	}
}

