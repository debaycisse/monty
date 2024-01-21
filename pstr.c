#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to a pointer that points at the top of a stack
 * @line_number: the line number of the executing command
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int val = 0;

	(void)line_number;
	if ((*stack) == NULL)
		printf("\n");
	else
	{
		while (current != NULL)
		{
			val = current->n;
			if ((val == 0) || ((val < 33) && (val > 127)))
				break;
			printf("%c", (char)current->n);
			current = (stack_t *)current->next;
		}
		printf("\n");
	}
}

/**
 * is_pstr - checks if the given opcode is equal to pstr
 * @opcode: the opcode to be checked
 * Return: 1, if the opcode is equal to pstr, else 0
 */
int is_pstr(char *opcode)
{
	if (strcmp(opcode, "pstr") == 0)
		return (1);
	return (0);
}
