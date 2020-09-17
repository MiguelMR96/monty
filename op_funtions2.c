#include "monty.h"
/**
 * op_pop -  removes the top element of the stack.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line)
{
	stack_t *aux;
	/*if there is not list or if the content is NULL*/
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line);
		free_stack(*stack);
		fclose(glob.fd);
		free(glob.buffer);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = aux->next;
	free(aux);
}
