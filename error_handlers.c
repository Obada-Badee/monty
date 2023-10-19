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

	fprintf(stderr, "L%d: usage: push integer\n", line_num);
	*exit_status = EXIT_FAILURE;
}

/**
 * op_not_exist - If the op_code is not found print error 
 * @op_code: The wrong op code
 * @line_num: The line number
 *
 * Return: Void
 */
void op_not_exist(char *op_code, int line_num)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
	*exit_status = EXIT_FAILURE;
}

/**
 * cant_open_file - If the file cant be opend prints error
 * @file: The path to the file 
 *
 * Return: Void
 */
void cant_open_file(char *file)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "Error: Can't open file %s\n", file);
	*exit_status = EXIT_FAILURE;
}

/**
 * argc_err - If: argc not 1 >> print error
 *
 * Return: Void
 */
void argc_err(void)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "USAGE: monty file\n");
	*exit_status = EXIT_FAILURE;
}


/**
 * malloc_err - If memory cant be allocated print message
 *
 * Return: Void
 */
void malloc_err(void)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "Error: malloc failed\n");
	*exit_status = EXIT_FAILURE;
}
