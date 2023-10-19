#include "monty.h"

/**
 * get_exit_status - Gets the last exit status and save it 
 *
 * Return: Pointer to last saved exit status
 */
int *get_exit_status(void)
{
	static int exit_status = EXIT_SUCCESS;

	return (&exit_status);
}
