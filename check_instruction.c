#include "monty.h"

stack_t *top = NULL;

/**
 * is_valid_instr - validates a line's content
 * @line: the line to be validated or checked
 * Return: 1 if it is valid, else 0
 */
int is_valid_instr(char *line)
{
	char *opcode = NULL, *argument = NULL, *delim = " \t\r\n$";
	int not_push = 0, not_pall = 0, not_num = 0;
	char *line_cpy = strdup(line);
	char *check_content = strtok(line_cpy, delim);

	if ((!check_content) || (strlen(check_content) < 4))
	{
		free(line_cpy);
		return (1);
	}
	free(line_cpy);
	line_cpy = NULL;
	line_cpy = strdup(line);
	opcode = strtok(line_cpy, delim);
	argument = strtok(NULL, delim);
	not_push = strcmp(opcode, "push") != 0;
	not_pall = strcmp(opcode, "pall") != 0;
	if (!not_push && argument != NULL)
		not_num = ((atoi(argument) == 0) && (strcmp(argument, "0") != 0));
	if ((not_push && not_pall) || (!not_push && argument == NULL))
	{
		free(line_cpy);
		return (0);
	}
	if (!not_push && not_num)
	{
		free(line_cpy);
		return (0);
	}
	free(line_cpy);
	return (1);
}

