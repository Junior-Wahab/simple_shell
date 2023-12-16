#include "shell.h"

/**
 * is_executable_file - Determines if a file is an executable command.
 *
 * @path: Path to the file.
 * Return: 1 if true, 0 otherwise.
 */
int is_executable_file(char *path)
{
    struct stat st;

    if (!path || stat(path, &st))
        return 0;

    return (st.st_mode & S_IFREG) ? 1 : 0;
}

/**
 * duplicate_characters - Duplicates characters from a given range.
 *
 * @pathstr: The PATH string.
 * @start: Starting index.
 * @stop: Stopping index.
 * Return: Pointer to a new buffer.
 */
char *duplicate_characters(char *pathstr, int start, int stop)
{
    static char buffer[1024];
    int k = 0;

    for (int i = start; i < stop; i++)
        if (pathstr[i] != ':')
            buffer[k++] = pathstr[i];

    buffer[k] = 0;
    return buffer;
}

/**
 * find_cmd_in_path - Finds the given command in the PATH string.
 *
 * @info: The info struct.
 * @pathstr: The PATH string.
 * @cmd: The command to find.
 * Return: Full path of the command if found, or NULL.
 */
char *find_cmd_in_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path;

    if (!pathstr)
        return NULL;

    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_executable_file(cmd))
            return cmd;
    }

    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            path = duplicate_characters(pathstr, curr_pos, i);
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }

            if (is_executable_file(path))
                return path;

            if (!pathstr[i])
                break;

            curr_pos = i;
        }
        i++;
    }

    return NULL;
}

