#include "monty.h"

/**
 * create_stack - Creates the stack from the given structure
 * @stack: A pointer to the stack to be created
 *
 * Return: EXIT_STATUS Corrospanding to each state
 */
int create_stack(stack_t **stack)
{
	stack_t *st;

	st = malloc(sizeof(stack_t));

	if (st == NULL)
	{
		return (EXIT_FAILURE);
	}

	st->n = STACK;
	st->next = NULL;
	st->prev = NULL;

	*stack = st;
	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees the memory occupied by stack 
 * @stack: The stack to be freed
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmpo = stack;

	while (stack)
	{
		tmpo = stack->next;
		free(stack);

		stack = tmpo;
	}
}
