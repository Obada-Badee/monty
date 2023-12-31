#include "monty.h"

/**
 * add - Add the top two elements of the stack
 * @stack: The stack to add its two elemnts
 * @line_num: The line number of the error
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *top = (*stack)->next;

	if (top == NULL || top->next == NULL)
	{
		empty_stack(line_num, "can't add, stack too short");
		return;
	}
	top->next->n += (top->n);
	pop(stack, line_num);
}

/**
 * nop - This function does NOTHING
 * @stack: The stack to do NOTHING in
 * @line_num: The line number of the error
 *
 * Return: void
 */
void nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_num)
{
}
