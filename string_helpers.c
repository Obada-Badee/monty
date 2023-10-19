#include "monty.h"

/**
 * is_atoi - It checks for a string is only numbers 
 *
 * Return: 1 if number, 0 if not 
 */
int is_atoi(void)
{
	int i;

	for (i = 0; opi_tok[1][i]; i++)
	{
		if (opi_tok[1][i] == '-' && i == 0)
			continue;
		if (opi_tok[1][i] < '0' || opi_tok[1][i] > '9')
			return (0);
	}
	return (1);
}

/**
 * split_string - Splits the string into tokens
 * @str: The string to be split
 * @delimiter: Delimiters
 *
 * Return: Splitted word array
 */
char **split_string(const char *str, const char *delimiter)
{
	char **words = NULL;
	char *str_copy = strdup(str);
	char *token = strtok(str_copy, delimiter);
	int count = 1;


	if (str == NULL)
		return (NULL);


	words = malloc(sizeof(char *));

	if (!words)
		return (NULL);

	words[0] = NULL;

	while (token != NULL)
	{
		words = _realloc(words, (count * sizeof(char *)),
				(count + 1) * sizeof(char *));

		if (!words)
			return (NULL);

		words[count - 1] = strdup(token);
		words[count] = NULL;

		count++;
		token = strtok(NULL, delimiter);
	}

	free(str_copy);

	return (words);
}
