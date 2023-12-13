#include "shell.h"
#include <sys/stat.h>

/**
 * find_the_path - finds the path
 * @command:  user given
 * @path: pointers to the desired executable file
 * Return: NULL 
 */
char *find_path(char *command, char *path[])
{
    char exec_path[BUFSIZE];
    struct stat file_stat;
    int i;

    if (stat(command, &file_stat) == 0 && file_stat.st_mode & S_IXUSR)
        return (command);

    for (i = 0; path[i] != NULL; i++)
    {
        snprintf(exec_path, sizeof(exec_path), "%s/%s", path[i], command);
        if (stat(exec_path, &file_stat) == 0 && file_stat.st_mode & S_IXUSR)
            return strdup(exec_path);
    }

    return NULL;
}

/**
 * initialize_path - initializes the path
 * @path_var: path variable
 * @path: the path
 * Return: nothing
 */
void init_path(char *path_var, char **path)
{
    size_t i = 0;
    char *token;

    token = strtok(path_var, ":");
    while (token != NULL)
    {
        path[i++] = token;
        token = strtok(NULL, ":");
    }
}

/**
 * print_env - print out the environment variables
 * @env: environment
 * Return: nothing
 */
void print_env(char **env)
{
	int i;

	if (env == NULL)
        return;

    for (i = 0; env[i] != NULL; i++)
        _print_str(env[i]);
}

