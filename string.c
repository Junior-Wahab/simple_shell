#include "shell.h"

/**
 * string_length - Returns the length of a string.
 * @str: The string whose length to check.
 *
 * Return: Integer length of the string.
 */
int string_length(char *str)
{
    int length = 0;

    if (!str)
        return 0;

    while (*str++)
        length++;

    return length;
}

/**
 * string_compare - Performs lexicographic comparison of two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2.
 */
int string_compare(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);

        s1++;
        s2++;
    }

    if (*s1 == *s2)
        return 0;
    else
        return (*s1 < *s2 ? -1 : 1);
}

/**
 * string_starts_with - Checks if the needle starts with the haystack.
 * @haystack: String to search.
 * @needle: The substring to find.
 *
 * Return: Address of the next character of haystack or NULL.
 */
char *string_starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return NULL;

    return (char *)haystack;
}

/**
 * string_concatenate - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Return: Pointer to the destination buffer.
 */
char *string_concatenate(char *dest, char *src)
{
    char *result = dest;

    while (*dest)
        dest++;

    while (*src)
        *dest++ = *src++;

    *dest = *src;
    return result;
}

