#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *top;
void malloc_error(void);
void usage_error(void);
int is_valid_instr(char *line);
void instruction_error(int line_number, char *line_r);
void opening_err(char *file_name);
void execute_opcode(char *line_r, int line_n);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void (*get_opcode(char *opcode))(stack_t **, unsigned int);
void free_stack(void);
void pint(stack_t **stack, unsigned int line_number);
void pint_error(int line_number);
int opcode_validator(char *op, char *arg);
int is_push(char *opcode, char *arg);
int is_pall(char *opcode);
int is_pint(char *opcode);
void pop(stack_t **stack, unsigned int line_number);
void pop_error(int line_number);
int is_pop(char *opcode);
void swap(stack_t **stack, unsigned int line_number);
void swap_error(int line_number);
int is_swap(char *opcode);
int stack_len(stack_t **stack);
void add_stack(stack_t **stack, unsigned int line_number);
void add_error(int line_number);
int is_add(char *opcode);
void nop(stack_t **stack, unsigned int line_number);
int is_nop(char *opcode);
void sub_stack(stack_t **stack, unsigned int line_number);
void sub_error(int line_number);
int is_sub(char *opcode);

#endif

