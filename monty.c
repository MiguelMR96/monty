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
	FILE *fd;
	char *buffer = NULL;
	size_t size;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*First: open the file*/
	fd = fopen(argv[1], "r");
	if(fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*Sec: we read the file*/
	while (getline(&buffer, &size, fd) != -1)
	{
		command(buffer);
	}
	fclose(fd);
	free(buffer);
	return 0;
}