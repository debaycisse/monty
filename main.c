#include "monty.h"

/***/
int main(int argc, char **argv)
{
	int fd, i = 0;
	char *error_message = NULL, *file_r = NULL, *token = NULL;

	if (argc != 2)
		usage_error();
	error_message = malloc(sizeof(char) * 100);
	if (error_message == NULL)
		malloc_error();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		strcpy(error_message, "Error: Can't open file ");
		strcat(error_message, argv[1]);
		strcat(error_message, "\n");
		write(2, error_message, strlen(error_message));
		free(error_message);
		exit(EXIT_FAILURE);
	}
	file_r = malloc(sizeof(char) * 5120);
	if (file_r == NULL)
		malloc_error();
	read(fd, file_r, sizeof(file_r));
	token = strtok(file_r, "\n");
	i = 1;
	while (token)
	{
		if (!check_instr(token))
			instruction_error(i, token); 
	}
	

	return (0);
}
