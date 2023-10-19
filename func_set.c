#include "monty.h"

/**
 * push - Pushs the element to stack/queue
 * @stack: The stack
 * @line_num: Used in case of error
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new, *tmp;

	if (opi_tok[1] == NULL)
	{
		argument_not_exist(line_num);
		return;
	}
	if (!is_atoi())
	{
		argument_not_exist(line_num);
		return;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		(malloc_err());
		return;
	}
	new->n = atoi(opi_tok[1]);
	if ((*stack)->n == STACK)
	{
		tmp = (*stack)->next;
		new->next = tmp;
		new->prev = *stack;
		if (tmp)
			(tmp)->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->prev = tmp;
	}
}


/**
 * pall - Prints all the elements in the stack
 * @stack: The stack to be printed
 *
 * Return: void
 */
void pall(stack_t **stack)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
