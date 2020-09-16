#include "monty.h"
/**
 * get_op - get opcode
 * @op_code: token_array[0]
 * @stack: pointer to stack
 * @line: line number
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int get_op(char *op_code, stack_t **stack, unsigned int line)
{
	instruction_t op_functions[] = {
		{"pall", op_pall},
		{NULL, NULL}
	};
	int i = 0;

	while (op_functions[i].opcode)
	{
		if (strcmp(op_functions[i].opcode, op_code) == 0)
		{
			op_functions[i].f(stack, line);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", line, op_code);
	return (EXIT_FAILURE);
}
