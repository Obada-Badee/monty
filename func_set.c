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
	stack_t *new, *tmpo;

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
		tmpo = (*stack)->next;
		new->next = tmpo;
		new->prev = *stack;
		if (tmpo)
			(tmpo)->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmpo = *stack;
		while (tmpo->next)
			tmpo = tmpo->next;
		tmpo->next = new;
		new->next = NULL;
		new->prev = tmpo;
	}
}


/**
 * pall - Prints all the elements in the stack
 * @stack: The stack to be printed
 * @line_num: Its not used but important
 *
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmpo = (*stack)->next;

	while (tmpo)
	{
		printf("%d\n", tmpo->n);
		tmpo = tmpo->next;
	}
}

/**
 * pint - Print the elements at the top of the stack
 * @stack: The stack to print from
 * @line_num: The line number of the error
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
		empty_stack(line_num, "can't pint, stack empty");
	else
		printf("%d\n", (*stack)->next->n);

}

/**
 * pop - Remove the elements at the top of the stack
 * @stack: The stack to remove form
 * @line_num: The line number of the error
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmpo = (*stack)->next;

	if (tmpo == NULL)
	{
		empty_stack(line_num, "can't pop an empty stack");
		return;
	}
	(*stack)->next = tmpo->next;
	tmpo->prev = *stack;
	free(tmpo);

}

/**
 * swap - Swap the top two elements of the stack
 * @stack: The stack to swap in
 * @line_num: The line number of the error
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *top = (*stack)->next;
	int tmpo;

	if (top == NULL || top->next == NULL)
	{
		empty_stack(line_num, "can't swap, stack too short");
		return;
	}
	tmpo = top->n;
	top->n = top->next->n;
	top->next->n = tmpo;
}
