#include "monty.h"

/**
 * execute_opcode - runs the opcode
 * @line_r: a given line's contents
 * @line_n: the line number that is being counted by i in mainc func.
 */
void execute_opcode(char *line_r, int line_n)
{
	char *op = NULL, *delim = " $\t\n\r", *line_num = NULL;
	char *line_cpy = strdup(line_r);
	void (*opcode)(stack_t **, unsigned int);
	unsigned int line_num_int;

	op = strtok(line_cpy, delim);
	line_num = strtok(NULL, delim);
	opcode = get_opcode(op);
	if ((opcode == NULL) || (!line_num && strcmp(op, "push") == 0))
		instruction_error(line_n, line_r);
	else if (!line_num && (strcmp(op, "push") != 0))
		line_num_int = line_n;
	else if ((line_num != NULL) || (strcmp(line_num, "0") == 0))
		line_num_int = (unsigned int)atoi(line_num);
	opcode(&top, line_num_int);
	free(line_cpy);
}

/**
 * get_opcode - gets the specific opcode function
 * @opcode: the given opcode, fetched from file
 * Return: function for the matched opcode or NULL if none matches
 */
void (*get_opcode(char *opcode))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add_stack},
		{"nop", nop}
	};
	int i;

	i = 0;
	while (i < 7)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}

