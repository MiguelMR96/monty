#include "monty.h"
/**
 * op_sub - subtracts the top element of the stack from the second top element of the stack.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int line)
{
	int num_nodes = 0, sub =0;
	stack_t *aux;
	
	aux = *stack;
	while (aux != NULL)
	{
		aux = aux->next;
		num_nodes++;
	}

	if (num_nodes < 2)
	{
		printf("L%d: can't sub, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;/*sumo stack y stakk next data*/
	(*stack) = (*stack)->next;/*stack ya será stack next para poder liberarlo*/
	free((*stack)->prev);/*libero stack*/
	(*stack)->prev = NULL;/*estack prev será NULL*/
	(*stack)->n = sub;/*stack data será la suma d elos dos anteriores */
}