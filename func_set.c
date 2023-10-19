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
