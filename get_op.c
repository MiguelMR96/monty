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
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"rotl", op_rotl},
		{"pchar", op_pchar},
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
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
