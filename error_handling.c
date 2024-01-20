#include "monty.h"

/**
 * usage_error - handles usage error message
 */
void usage_error(void)
{
	write(2, "USAGE: monty file\n", 19);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - handles malloc error message
 */
void malloc_error(void)
{
	write(2, "Error: malloc failed\n", 22);
	free_stack();
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
	free(error_msg);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * opening_err - handles opening error
 * @file_name: the name of the file that could not be opened
 */
void opening_err(char *file_name)
{
	char *error_message = malloc(sizeof(char) * 100);

	if (error_message == NULL)
		malloc_error();
	strcpy(error_message, "Error: Can't open file ");
	strcat(error_message, file_name);
	strcat(error_message, "\n");
	write(2, error_message, strlen(error_message));
	free(error_message);
	exit(EXIT_FAILURE);
}

