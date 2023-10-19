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

/**
 * _realloc - Reallocate memory block using malloc and free
 * @ptr: A pointer to the memory previously allocated
 * @old_size: The size of the allocated space for ptr
 * @new_size: The size of the new memory block
 *
 * Return: A pointer to the allocated memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *arr;
	unsigned int i;
	unsigned int copy_size = old_size;

	if (!ptr)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	else if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size < old_size)
	{
		copy_size = new_size;
	}

	arr = malloc(new_size);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < copy_size; i++)
		*(arr + i) = *((char *)ptr + i);

	free(ptr);

	return (arr);
}

/**
 * clean - Custom Freeing functions for poiter to pointer
 * @array: The array to be freed
 *
 * Return: void
 */
void clean(char **array)
{
	int i;

	if (array == NULL)
		return;

	for (i = 0; array[i]; i++)
		free(array[i]);

	free(array);
}
