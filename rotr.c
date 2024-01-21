#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to a pointer that points at the top of the stack
 * @line_number: line number of the currently running command
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last_node = NULL;

	(void)line_number;
	last_node = top;
	if (stack_len(stack) >= 2)
	{
		while (last_node)
		{
			if (last_node->next == NULL)
				break;
			last_node = (stack_t *)last_node->next;
		}
		(last_node->prev)->next = NULL;
		last_node->prev = NULL;
		last_node->next = (struct stack_s *)top;
		top->prev = (struct stack_s *)last_node;
		top = last_node;
	}
}

/**
 * is_rotr - checks if the opcode is equal to rotr
 * @opcode: the opcode to be checked
 * Return: 1, if the given opcode is equal to rotr, else 0
 */
int is_rotr(char *opcode)
{
	if (strcmp(opcode, "rotr") == 0)
		return (1);
	return (0);
}

