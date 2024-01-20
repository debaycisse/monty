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
	if (opcode_validator(opcode, argument))
	{
		free(line_cpy);
		return (1);
	}
	free(line_cpy);
	return (0);
}

/**
 * opcode_validator - checks validity of a given opcode
 * @op: opcode to be checked
 * @arg: the line number argument
 * Return: 1, if a given opcode exists, 0 otherwise
 */
int opcode_validator(char *op, char *arg)
{
	char *opcodes[] = {
		"push", "pall", "pint"
	};
	int i;

	for (i = 0; i < 3; i++)
	{
		if (strcmp(opcodes[i], op) == 0)
		{
			if (is_push(op, arg) || is_pall(op) || is_pint(op))
				return (1);
		}
	}
	return (0);
}

/**
 * is_push - checks whether an opcode is push or not
 * @opcode: opcode to be checked
 * @arg: the line number argument
 * Return: 1, if a given opcode exists, 0 otherwise
 */
int is_push(char *opcode, char *arg)
{
	int is_psh = strcmp(opcode, "push") == 0;
	int is_nm = 0;

	if (arg == NULL)
		return (0);
	is_nm = ((atoi(arg) > 0) || ((atoi(arg) == 0) && (strcmp(arg, "0") == 0)));
	if (is_psh && is_nm)
		return (1);
	return (0);
}

/**
 * is_pall - checks validity of a given opcode
 * @opcode: opcode to be checked
 * Return: 1, if a given opcode exists, 0 otherwise
 */
int is_pall(char *opcode)
{
	if (strcmp(opcode, "pall") == 0)
		return (1);
	return (0);
}

/**
 * is_pint - it prints the value at the top of the queue
 * @opcode: test, if the opcode exists at all
 * Return: 1, if a given opcode exists, 0 otherwise
 */
int is_pint(char *opcode)
{
	if (strcmp(opcode, "pint") == 0)
		return (1);
	return (0);
}
