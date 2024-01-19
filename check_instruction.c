#include "monty.h"

/**
 * check_instr - validates a line
 * @line: the line to be validated or checked
 * Return: 1 if it is valid, else 0
 */
int check_instr(char *line)
{
	char *opcode = NULL, *argument = NULL, *delim = " \t\r\n$";
	int not_push = 0, not_pall = 0, not_num = 0;
	char *line_cpy = malloc(sizeof(char) * strlen(line) + 1);

	strcpy(line_cpy, line);
	opcode = strtok(line_cpy, delim);
	argument = strtok(NULL, delim);
	not_push = strcmp(opcode, "push") != 0;
	not_pall = strcmp(opcode, "pall") != 0;
	not_num = atoi(argument) == 0;
	if (not_push && not_pall)
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
