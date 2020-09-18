#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct globales_s - Global varaibles
 * @fd: file descriptor
 * @buffer: getline´s buffer
 *
 * Description: global variables
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globales_s
{
	FILE *fd;
	char *buffer;
} glob_t;

extern glob_t glob;
glob_t glob;

int command(char *buffer, stack_t **stack, unsigned int line);
int get_op(char *op_code, stack_t **stack, unsigned int line);

stack_t *op_push(stack_t **stack, char *token, unsigned int line);
void op_pstr(stack_t **stack, unsigned int line);
void op_pchar(stack_t **stack, unsigned int line);
void op_pall(stack_t **stack, unsigned int line);
void op_pint(stack_t **stack, unsigned int line);
void op_pop(stack_t **stack, unsigned int line);
void op_swap(stack_t **stack, unsigned int line);
void op_add(stack_t **stack, unsigned int line);
void op_nop(stack_t **stack, unsigned int line);

void op_sub(stack_t **stack, unsigned int line);
void op_div(stack_t **stack, unsigned int line);
void op_mul(stack_t **stack, unsigned int line);
void op_mod(stack_t **stack, unsigned int line);
void op_rotl(stack_t **stack, unsigned int line);

void free_stack(stack_t *stack);

#endif
