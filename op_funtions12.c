#include "monty.h"
/**
 * op_pstr - print string from stack
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int line)
{
	stack_t *aux = *stack;
	(void)line;

	while (aux)
	{
		if (aux->n <= 0 || aux->n > 127)
			break;
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
