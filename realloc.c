#include "shell.h"

/**
 * _memset - Fills memory with a constant byte.
 *
 * @s: Pointer to the memory area.
 * @b: The byte to fill *s with.
 * @n: The amount of bytes to be filled.
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        s[i] = b;
    return s;
}

/**
 * free_string_array - Frees an array of strings.
 *
 * @str_array: Array of strings.
 */
void free_string_array(char **str_array)
{
    char **temp = str_array;

    if (!str_array)
        return;

    while (*str_array)
        free(*str_array++);

    free(temp);
}

/**
 * custom_realloc - Reallocates a block of memory.
 *
 * @ptr: Pointer to the previous malloc'ated block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 * Return: Pointer to the reallocated block.
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;

    if (!ptr)
        return malloc(new_size);

    if (!new_size)
        return (free(ptr), NULL);

    if (new_size == old_size)
        return ptr;

    new_ptr = malloc(new_size);

    if (!new_ptr)
        return NULL;

    old_size = old_size < new_size ? old_size : new_size;

    while (old_size--)
        new_ptr[old_size] = ((char *)ptr)[old_size];

    free(ptr);
    return new_ptr;
}

