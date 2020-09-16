#include "monty.h"
/**
 * free_stack - frees the stack
 * @stack: pointer to stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *aux = stack;

	while (aux)
	{
		aux = aux->next;
		free(stack);
		stack = aux;
	}
}
/**
 * free_token - 