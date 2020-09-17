#include "monty.h"
/**
 * main - Main function
 * @argc: Number of arguments
 * @argv: Array of arguments of main.
 *
 * Return: 0 if succes
 */
int main(int argc, char *argv[])
{
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int line = 1;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/*First: open the file*/
	glob.fd = fopen(argv[1], "r");
	if (glob.fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	/*Sec: we read the file*/
	glob.buffer = NULL;
	while (getline(&glob.buffer, &size, glob.fd) != -1)
	{
		command(glob.buffer, &stack, line);
		line++;
	}
	fclose(glob.fd);
	free(glob.buffer);
	free_stack(stack);
	return (0);
}
