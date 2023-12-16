#include "shell.h"

/**
 * my_env - Prints the current environment.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int my_env(info_t *info)
{
    print_environment(info->env);
    return 0;
}

/**
 * get_environment_variable - Gets the value of an environment variable.
 * @info: Structure containing potential arguments.
 * @name: Environment variable name.
 *
 * Return: The value of the environment variable.
 */
char *get_environment_variable(info_t *info, const char *name)
{
    list_t *node = info->env;
    char *value;

    while (node)
    {
        value = starts_with(node->str, name);
        if (value && *value)
            return value;

        node = node->next;
    }

    return NULL;
}

/**
 * my_setenv - Initializes a new environment variable or modifies an existing one.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int my_setenv(info_t *info)
{
    if (info->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return 1;
    }

    if (set_environment_variable(info, info->argv[1], info->argv[2]))
        return 0;

    return 1;
}

/**
 * my_unsetenv - Removes an environment variable.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int my_unsetenv(info_t *info)
{
    int i;

    if (info->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return 1;
    }

    for (i = 1; i <= info->argc; i++)
        unset_environment_variable(info, info->argv[i]);

    return 0;
}

/**
 * populate_environment_list - Populates the environment linked list.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int populate_environment_list(info_t *info)
{
    list_t *environment_list = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
        add_node_end(&environment_list, environ[i], 0);

    info->env = environment_list;
    return 0;
}

