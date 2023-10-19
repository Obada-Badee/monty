#include "monty.h"

/**
 * argument_not_exist - Print the error mesaage if 
 * 			<int> is not an integer or 
 * 			if there is no argument given to push
 * @line_num: The line where error reside
 *
 * Return: void
 */
void argument_not_exist(int line_num)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	*exit_status = EXIT_FAILURE;
}
