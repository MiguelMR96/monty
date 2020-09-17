#include "monty.h"
/**
 * op_add - adds the top two elements of the stack.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line)
{
	int num_nodes = 0, add = 0;
	stack_t *aux;

	aux = *stack;
	while (aux != NULL)
	{
		aux = aux->next;
		num_nodes++;
	}

	if (num_nodes < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	add = (*stack)->n + (*stack)->next->n;/*sumo stack y stakk next data*/
	(*stack) = (*stack)->next;/*stack ya será stack next para poder liberarlo*/
	free((*stack)->prev);/*libero stack*/
	(*stack)->prev = NULL;/*estack prev será NULL*/
	(*stack)->n = add;/*stack data será la suma d elos dos anteriores */
}
