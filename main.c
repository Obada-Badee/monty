#include "monty.h"

/**
 * main - Main Func. to run the monty file 
 * @argc: Number of arguments
 * @argv: The arguments array
 *
 * Return: Last exit status
 */
int main(int argc, char **argv)
{
	int *exit_status = get_exit_status();
	FILE *page = NULL;

	page = fopen(argv[1], "r");

	read_page(page);
	fclose(script);

	return (*exit_status);
}
