#include "monty.h"

/**
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_item = NULL;
	top = *stack;

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		write(2, "Error: malloc failed\n", 22);
		free(new_item);
		exit(EXIT_FAILURE);	
	}
	if ((isdigit(atoi(line_number)) == 0) || !line_number)
	{
		write(2, "L<line_number>: usage: push integer", 50);
	}
	new_item->n = data;
	new_item->prev = NULL;
	if (top == NULL)
	{
		top = new_item;
		new_item->next = NULL;
	}
	else
	{
		top->prev = (stack_s *)new_item;
		new_item->next = (stack_s *)top;
		top = new_item;
	}
}
