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
	else if ((int)opcode[0] == (int)'#')
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
		"push", "pall", "pint", "pop", "swap", "add", "nop", "sub",
		"div", "mul", "mod", "#", "pchar", "pstr", "rotl", "rotr"
	};
	int i;

	for (i = 0; i < 16; i++)
	{
		if (strcmp(opcodes[i], op) == 0)
		{
			if (is_push(op, arg) || is_pall(op) || is_pint(op) ||
				is_pop(op) || is_swap(op) || is_add(op) || is_nop(op) ||
				is_sub(op) || is_div(op) || is_mul(op) || is_mod(op) ||
				is_comment(op) || is_pchar(op) || is_pstr(op) || is_rotl(op) ||
				is_rotr(op)
				)
				return (1);
		}
	}
	return (0);
}

