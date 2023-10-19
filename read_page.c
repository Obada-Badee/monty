#include "monty.h"
/**
 * get_func - Choose the the function to be executed
 * @op_code: The Function code 
 *
 * Return: A pointer to the function or NULL 
 */
opi_func *get_func(char *op_code)
{
	int i;
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(op_funcs[i].opcode, op_code) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * check_delim - Check the line for delimitires
 * @line: The line
 * @delim: The Delimeters to be searched
 *
 * Return: 1 or 0
 */
int check_delim(char *line, char *delim)
{
        int i, j;

        for (i = 0; line[i]; i++)
        {
                for (j = 0; delim[j]; j++)
                {
                        if (line[i] == delim[j])
                                break;
                }
                if (delim[j] == '\0')
                        return (0);
        }

        return (1);
}

/**
 * read_page - Reads the instruction page one by one 
 * @page: A pointer to the page 
 *
 * Return: void
 */
void read_page(FILE *page)
{
	int line_num = 0, *exit_status = get_exit_status();
	size_t len;
	opi_func *func;
	char *line = NULL;
	stack_t *stack = NULL;

	*exit_status = create_stack(&stack);
	if (*exit_status == EXIT_FAILURE)
		return;

	while ((getline(&line, &len, page) != -1))
	{
		line_num++;
		if (check_delim(line, DELIMS) || line[0] == '#')
			continue;
		opi_tok = split_string(line, DELIMS);
		if (opi_tok == NULL)
		{
			free_stack(stack);
			malloc_err();
			break;
		}

		func = get_func(opi_tok[0]);
		if (func == NULL)
		{
			op_not_exist(opi_tok[0], line_num);
			clean(opi_tok);
			break;
		}
		func(&stack, line_num);
		clean(opi_tok);
		if (*exit_status == EXIT_FAILURE)
			break;
	}
	free_stack(stack);
	free(line);
}
