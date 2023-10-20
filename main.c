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

	if (argc != 2)
	{
		argc_err();
	}
	else
	{
		page = fopen(argv[1], "r");
		if (page == NULL)
		{
			cant_open_file(argv[1]);
		}
		else
		{
			read_page(page);
			fclose(page);
		}
	}

	return (*exit_status);
}
