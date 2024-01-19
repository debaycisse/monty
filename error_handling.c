#include "monty.h"

/**
 * usage_error - handles usage error message
 */
void usage_error()
{
	write(2, "USAGE: monty file\n", 19);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - handles malloc error message
 */
void malloc_error()
{
	write(2, "Error: malloc failed\n", 22);
	exit(EXIT_FAILURE);
}

/**
 * instruction_error - handles instruction-syntax error message
 * @line_number: the number of line where bad syntax exists
 * @line_r: the full content of the line
 */
void instruction_error(int line_number, char *line_r)
{
	char *error_msg = malloc(sizeof(char) * 40);
	char *op = strtok(line_r, " /r/t/n$");

	sprintf(error_msg, "L%i: unknown instruction %s\n", line_number, op);
	write(2, error_msg, strlen(error_msg));
	exit(EXIT_FAILURE);
}

