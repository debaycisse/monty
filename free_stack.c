#include "monty.h"

/**
 * free_stack - frees up the used memory
 */
void free_stack(void)
{
	stack_t *temp = NULL;

	while (top != NULL)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}

