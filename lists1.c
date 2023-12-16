#include "shell.h"

/**
 * create_node - Creates a new node with given string and index.
 *
 * @str: String field of the node.
 * @num: Node index used by history.
 * Return: A newly created node.
 */
list_t *create_node(const char *str, int num)
{
    list_t *newNode = malloc(sizeof(list_t));

    if (!newNode)
        return NULL;

    _memset(newNode, 0, sizeof(list_t));
    newNode->num = num;

    if (str)
    {
        newNode->str = _strdup(str);
        if (!newNode->str)
        {
            free(newNode);
            return NULL;
        }
    }

    return newNode;
}

/**
 * add_node_at_beginning - Adds a node to the beginning of the list.
 *
 * @head: Address of the pointer to the head node.
 * @str: String field of the node.
 * @num: Node index used by history.
 * Return: Pointer to the newly added node.
 */
list_t *add_node_at_beginning(list_t **head, const char *str, int num)
{
    list_t *newNode = create_node(str, num);

    if (!head || !newNode)
        return NULL;

    newNode->next = *head;
    *head = newNode;
    return newNode;
}

/**
 * add_node_at_end - Adds a node to the end of the list.
 *
 * @head: Address of the pointer to the head node.
 * @str: String field of the node.
 * @num: Node index used by history.
 * Return: Pointer to the newly added node.
 */
list_t *add_node_at_end(list_t **head, const char *str, int num)
{
    list_t *newNode = create_node(str, num);

    if (!head || !newNode)
        return NULL;

    if (*head)
    {
        list_t *currentNode = *head;
        while (currentNode->next)
            currentNode = currentNode->next;

        currentNode->next = newNode;
    }
    else
    {
        *head = newNode;
    }

    return newNode;
}

/**
 * print_str_list - Prints only the str element of a list_t linked list.
 *
 * @head: Pointer to the first node.
 * Return: Size of the list.
 */
size_t print_str_list(const list_t *head)
{
    size_t size = 0;

    while (head)
    {
        _puts(head->str ? head->str : "(nil)");
        _puts("\n");
        head = head->next;
        size++;
    }

    return size;
}

/**
 * delete_node_at_index - Deletes a node at a given index.
 *
 * @head: Address of the pointer to the first node.
 * @index: Index of the node to delete.
 * Return: 1 on success, 0 on failure.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    if (!head || !*head)
        return 0;

    list_t *currentNode = *head;
    if (index == 0)
    {
        *head = currentNode->next;
        free_node(currentNode);
        return 1;
    }

    list_t *previousNode = NULL;
    for (unsigned int i = 0; i < index && currentNode; i++)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode)
    {
        previousNode->next = currentNode->next;
        free_node(currentNode);
        return 1;
    }

    return 0;
}

/**
 * free_str_list - Frees all nodes of a list.
 *
 * @head: Address of the pointer to the head node.
 * Return: Void.
 */
void free_str_list(list_t **head)
{
    if (!head || !*head)
        return;

    list_t *currentNode = *head;
    while (currentNode)
    {
        list_t *nextNode = currentNode->next;
        free_node(currentNode);
        currentNode = nextNode;
    }

    *head = NULL;
}

/**
 * free_node - Frees memory allocated for a list node.
 *
 * @node: The node to free.
 * Return: Void.
 */
void free_node(list_t *node)
{
    if (node)
    {
        free(node->str);
        free(node);
    }
}

