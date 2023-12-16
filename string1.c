#include "shell.h"

/**
 * copy_string - Copies a string.
 * @destination: The destination buffer.
 * @source: The source string.
 *
 * Return: Pointer to the destination buffer.
 */
char *copy_string(char *destination, const char *source)
{
    int index = 0;

    if (destination == source || source == NULL)
        return destination;

    while (source[index])
    {
        destination[index] = source[index];
        index++;
    }

    destination[index] = '\0';
    return destination;
}

/**
 * duplicate_string - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string.
 */
char *duplicate_string(const char *str)
{
    int length = 0;
    char *result;

    if (str == NULL)
        return NULL;

    while (*str++)
        length++;

    result = malloc(sizeof(char) * (length + 1));
    if (!result)
        return NULL;

    for (length++; length--;)
        result[length] = *--str;

    return result;
}

/**
 * print_string - Prints a string.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */
void print_string(char *str)
{
    int index = 0;

    if (!str)
        return;

    while (str[index] != '\0')
    {
        print_character(str[index]);
        index++;
    }
}

/**
 * print_character - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_character(char c)
{
    static int index;
    static char buffer[WRITE_BUFFER_SIZE];

    if (c == BUF_FLUSH || index >= WRITE_BUFFER_SIZE)
    {
        write(1, buffer, index);
        index = 0;
    }

    if (c != BUF_FLUSH)
        buffer[index++] = c;

    return 1;
}

