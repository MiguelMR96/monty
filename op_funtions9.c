#include "monty.h"
/**
 * op_mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_mod(stack_t **stack, unsigned int line)
{
	int num_nodes = 0, mod = 0;
	stack_t *aux;

	aux = *stack;
	while (aux != NULL)
	{
		aux = aux->next;
		num_nodes++;
	}

	if (num_nodes < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line);
		free_stack(*stack);
		fclose(glob.fd);
		free(glob.buffer);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line);
		free_stack(*stack);
		fclose(glob.fd);
		free(glob.buffer);
		exit(EXIT_FAILURE);
	}

	mod = (*stack)->next->n % (*stack)->n;/*sumo stack y stakk next data*/
	(*stack) = (*stack)->next;/*stack ya será stack next para poder liberarlo*/
	free((*stack)->prev);/*libero stack*/
	(*stack)->prev = NULL;/*estack prev será NULL*/
	(*stack)->n = mod;/*stack data será la suma d elos dos anteriores */
}
