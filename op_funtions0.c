#include "monty.h"
/**
 * op_push - push function
 * @stack: pointer to doubly linked list
 * @n: node's value (stack->n)
 * @line: number of line
 * Return: int
 */
stack_t *op_push(stack_t **stack, int n, unsigned int line)
{
	stack_t *new_node;
	(void)line;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = *stack;/*El prox nodo actual sería head*/
	new_node->prev = NULL;/*El nodo prev al primero es NULL*/
	if (*stack == NULL)/*Creo la lista si no existe*/
	{
		*stack = new_node;
		return (new_node);
	}
	(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
	return (new_node);
}
/**
 * op_pall - print all nodes in stack
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line)
{
	stack_t *aux = *stack;
	(void)line;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
