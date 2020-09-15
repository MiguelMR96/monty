#include "monty.h"
/**
 * command -
 * 
 */
void command(char *buffer)
{
	/*Tokenize the content od the file*/
	char *token, **token_array;
	int i = 0;

	token_array = malloc(sizeof(char *) * 1024);
	token = strtok(buffer, " \t");
	
	while (token)
	{
		token_array[i] = token;
		token = strtok(NULL, " \t");
		i++;
	}
	token_array[i] = NULL;
	printf("%s\n", token_array[0]);
	
	free(token_array);
}
