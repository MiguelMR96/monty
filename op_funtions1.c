#include "monty.h"
/**
 * op_pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line)
{
	/*if there is not list or if the content is NULL*/
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
