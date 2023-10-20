#ifndef MONTY_H
#define MONTY_H

#define STACK 1
#define QUEUE 2
#define DELIMS " \n\t"
#define _GNU_SOURCE

/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Structrues */
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

typedef void opi_func(stack_t **stack, unsigned int line_number);

/* Global variables */
extern char **opi_tok;

/* helpers */
int *get_exit_status(void);
int is_atoi(void);
char **split_string(const char *str, const char *delimiter);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void clean(char **array);

/* stack helpers */
int create_stack(stack_t **stack);
void free_stack(stack_t *stack);

/* error handlers */
void argument_not_exist(int line_num);
void op_not_exist(char *op_code, int line_num);
void cant_open_file(char *file);
void argc_err(void);

/* Read Function */
void read_page(FILE *page);
void malloc_err(void);

/* Operation Functions */
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number);


#endif /* MONTY_H */
