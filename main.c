#include "monty.h"

/**
 * main - entry to the program
 * @argc: the argument counter
 * @argv: the list of passed arguments to the program
 * Return: 0, if no error
 */
int main(int argc, char **argv)
{
	int i = 0;
	FILE *file =  NULL;
	char buffer[100];
	char *token = NULL;

	if (argc != 2)
		usage_error();
	file = fopen(argv[1], "r");
	if (!file)
		opening_err(argv[1]);
	i = 1;
	fgets(buffer, sizeof(buffer), file);
	while (buffer != NULL)
	{
		if (feof(file))
			break;
		token = strtok(buffer, "$");
		if (!is_valid_instr(token))
			instruction_error(i, token);
		execute_opcode(token, i);
		i++;
		fgets(buffer, sizeof(buffer), file);
	}
	free_stack();
	fclose(file);
	return (0);
}

