#include "shell.h"

/**
 * get_list_length - Determines the length of a linked list.
 *
 * @head: Pointer to the first node.
 * Return: Size of the list.
 */
size_t get_list_length(const list_t *head)
{
    size_t length = 0;

    while (head)
    {
        head = head->next;
        length++;
    }
    return length;
}

/**
 * list_to_array - Converts a linked list to an array of strings.
 *
 * @head: Pointer to the first node.
 * Return: Array of strings.
 */
char **list_to_array(list_t *head)
{
    list_t *node = head;
    size_t length = get_list_length(head);
    char **strings;
    char *str;

    if (!head || !length)
        return NULL;

    strings = malloc(sizeof(char *) * (length + 1));
    if (!strings)
        return NULL;

    for (size_t i = 0; node; node = node->next, i++)
    {
        str = _strdup(node->str);
        if (!str)
        {
            for (size_t j = 0; j < i; j++)
                free(strings[j]);
            free(strings);
            return NULL;
        }
        strings[i] = str;
    }
    strings[length] = NULL;
    return strings;
}

/**
 * print_list_elements - Prints all elements of a list_t linked list.
 *
 * @head: Pointer to the first node.
 * Return: Size of the list.
 */
size_t print_list_elements(const list_t *head)
{
    size_t length = 0;

    while (head)
    {
        _puts(convert_number(head->num, 10, 0));
        _putchars(':', ' ');
        _puts(head->str ? head->str : "(nil)");
        _puts("\n");
        head = head->next;
        length++;
    }
    return length;
}

/**
 * find_node_with_prefix - Returns the node whose string starts with a prefix.
 *
 * @head: Pointer to the list head.
 * @prefix: String to match.
 * @c: The next character after the prefix to match.
 * Return: Matching node or NULL.
 */
list_t *find_node_with_prefix(list_t *head, char *prefix, char c)
{
    char *start = NULL;

    while (head)
    {
        start = starts_with(head->str, prefix);
        if (start && ((c == -1) || (*start == c)))
            return head;
        head = head->next;
    }
    return NULL;
}

/**
 * get_node_index - Gets the index of a node.
 *
 * @head: Pointer to the list head.
 * @node: Pointer to the node.
 * Return: Index of the node or -1.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
    size_t index = 0;

    while (head)
    {
        if (head == node)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

