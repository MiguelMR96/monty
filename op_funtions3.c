#include "monty.h"
/**
 * op_swap  - swaps the top two elements of the stack.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line)
{
	stack_t *aux, *tmp = *stack;
	int counter = 1;

	while (tmp->next)
	{
		tmp = tmp->next;
		counter++;
	}

	if (counter < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line);
		free_stack(*stack);
		fclose(glob.fd);
		free(glob.buffer);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	(*stack)->next = aux->next;
	if (aux->next)
		aux->next->prev = *stack;
	aux->next = *stack;
	(*stack)->prev = aux;
	aux->prev = NULL;

	*stack = aux;
}
