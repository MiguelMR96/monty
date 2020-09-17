#include "monty.h"
/**
 * op_rotl - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_rotl(stack_t **stack, unsigned int line)
{
	stack_t *prev, *cur;
	(void)line;

	if ((*stack) == NULL)
	{
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack) != NULL)
	{
		prev = (*stack);
		cur = (*stack)->next;
		(*stack) = (*stack)->next;
	}
	prev->next = NULL;/*el primer nodo será el último nodo*/
	while ((*stack) != NULL)
	{
		(*stack) = (*stack)->next;
		cur->next = prev;/*se conencta el nodo actual con prev*/
		prev = cur;
		cur = (*stack);/*nodo prev al actual y actual a stack*/
	}
	(*stack) = prev;/*se hace stack el último nodo*/
}
