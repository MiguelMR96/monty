#include "monty.h"
/**
 * op_div  - divides the second top element of the stack by the top element of
 * the stack.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_div(stack_t **stack, unsigned int line)
{
	int num_nodes = 0, div = 0;
	stack_t *aux;

	aux = *stack;
	while (aux != NULL)
	{
		aux = aux->next;
		num_nodes++;
	}

	if (num_nodes < 2)
	{
		dprintf(2,"L%d: can't div, stack too short\n", line);
		free_stack(*stack);
		fclose(glob.fd);
		free(glob.buffer);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;/*sumo stack y stakk next data*/
	(*stack) = (*stack)->next;/*stack ya será stack next para poder liberarlo*/
	free((*stack)->prev);/*libero stack*/
	(*stack)->prev = NULL;/*estack prev será NULL*/
	(*stack)->n = div;/*stack data será la suma d elos dos anteriores */
}
