#include "monty.h"
/**
 * op_pchar - print integer in char
 * @stack: pointer to stack
 * @line: line number
 * Return:void
 */
void op_pchar(stack_t **stack, unsigned int line)
{
	int n;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line);
		free(glob.buffer);
		fclose(glob.fd);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (n < 0 || n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line);
		fclose(glob.fd);
		free_stack(*stack);
		free(glob.buffer);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}
