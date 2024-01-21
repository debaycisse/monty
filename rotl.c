#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to a pointer that points at the top of the stack
 * @line_number: line number of the currently running command
 *
 * Description: The top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *prev_top = NULL, *last_node = NULL;

	(void)line_number;
	top = *stack;
	prev_top = top;
	last_node = top;
	if (stack_len(stack) >= 2)
	{
		top = (stack_t *)top->next;
		top->prev = prev_top->prev;
		while (last_node)
		{
			if (last_node->next == NULL)
				break;
			last_node = last_node->next;
		}
		last_node->next = (struct stack_s *)prev_top;
		prev_top->prev = (struct stack_s *)last_node;
		prev_top->next = NULL;
	}
}

/**
 * is_rotl - checks if the opcode is equal to rotl
 * @opcode: the opcode to be checked or compared
 * Return: 1, if the opcode is equak to rotl, else 0
 */
int is_rotl(char *opcode)
{
	if (strcmp(opcode, "rotl") == 0)
		return (1);
	return (0);
}

