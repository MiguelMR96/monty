#include "monty.h"
/**
 * op_mul - multiplies the second top element of the stack with the top element of the stack.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int line)
{
	int num_nodes = 0, mul =0;
	stack_t *aux;
	
	aux = *stack;
	while (aux != NULL)
	{
		aux = aux->next;
		num_nodes++;
	}

	if (num_nodes < 2)
	{
		printf("L%d: can't mul, stack too short\n", line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->next->n * (*stack)->n;/*sumo stack y stakk next data*/
	(*stack) = (*stack)->next;/*stack ya será stack next para poder liberarlo*/
	free((*stack)->prev);/*libero stack*/
	(*stack)->prev = NULL;/*estack prev será NULL*/
	(*stack)->n = mul;/*stack data será la suma d elos dos anteriores */
}