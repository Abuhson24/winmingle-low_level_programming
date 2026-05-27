#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to previously allocated memory
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: new size in bytes for the new memory block
 *
 * Return: pointer to reallocated memory, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i;
	char *old_char;
	char *new_char;

	/* If new_size equals old_size, do nothing and return ptr */
	if (new_size == old_size)
		return (ptr);

	/* If ptr is NULL, equivalent to malloc(new_size) */
	if (ptr == NULL)
		return (malloc(new_size));

	/* If new_size is 0 and ptr is not NULL, free ptr and return NULL */
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	/* Allocate new memory block */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Copy contents from old to new up to min(old_size, new_size) */
	old_char = (char *)ptr;
	new_char = (char *)new_ptr;

	for (i = 0; i < old_size && i < new_size; i++)
		new_char[i] = old_char[i];

	/* Free the old pointer */
	free(ptr);

	/* Return pointer to new memory block */
	return (new_ptr);
}
