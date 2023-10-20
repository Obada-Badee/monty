#include "monty.h"

/**
 * empty_stack - Handles Empty stacks error message
 * @line_num: The line number of the error
 * @error_msg: The message to be printed
 *
 * Return: Void
 */
void empty_stack(int line_num, char *error_msg)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "L%d: %s\n", line_num, error_msg);
	*exit_status = EXIT_FAILURE;
}
