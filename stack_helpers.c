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

	if (s == NULL)
	{
		return (EXIT_FAILURE);
	}

	st->n = STACK;
	st->next = NULL;
	st->prev = NULL;

	*stack = st;
	return (EXIT_SUCCESS);
}
