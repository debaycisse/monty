#include "monty.h"

/**
 * _push - pushes an item on to the stack, using LIFO
 * @stack: pointer to a pointer that points to the top of the stack
 * @line_number: line number (data, stored in stack), gotten from a given file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_item = NULL;
	int data = (int)line_number;

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		write(2, "Error: malloc failed\n", 22);
		free(new_item);
		free_stack();
		exit(EXIT_FAILURE);
	}
	new_item->n = data;
	new_item->prev = NULL;
	if (*stack == NULL)
	{
		top = new_item;
		new_item->next = NULL;
	}
	else
	{
		top->prev = (struct stack_s *)new_item;
		new_item->next = (struct stack_s *)top;
		top = new_item;
	}
}

