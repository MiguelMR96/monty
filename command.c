#include "monty.h"
/**
 * command - functions that tokenize getline buffer
 * @buffer: getline's buffer with the commands and args
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void command(char *buffer, stack_t **stack, unsigned int line)
{
	/*Tokenize the content od the file*/
	char *token, **token_array;
	int n = 0, i = 0;
	stack_t *aux;
	(void)aux;

	token_array = malloc(sizeof(char *) * 1024);
	if (token_array == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " \t\n");

	while (token)
	{
		token_array[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	token_array[i] = NULL;

	if (strcmp(token_array[0], "push") == 0)
	{
		n = atoi(token_array[1]);
		aux = op_push(stack, n, line);
	}
	else
	{
		get_op(token_array[0], stack, line);
	}
	free(token_array);
}
