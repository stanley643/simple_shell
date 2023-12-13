#include "shell.h"

/**
 * main - the shell playground
 * Return: 0 on success or something else
 */
int main(int argc, char **argv, char **envp)
{
    char *input_line = NULL;
    ssize_t input_size;
    size_t line_length = 0;
    pid_t child_pid;
    char *arguments[MAX_ARGS];
    char *executable_path, *environment;
    char *search_paths[MAX_ARGS];
    char *path_variable, *exit_command;
    int path_index;

    (void)argc;
    (void)argv;
    exit_command = "exit";
    environment = "env";
    path_variable = getenv("PATH");
    if (path_variable == NULL)
    {
        perror("./hsh");
        return (EXIT_FAILURE);
    }

    path_index = 0;
    search_paths[path_index++] = strtok(path_variable, ":");
    while ((search_paths[path_index] = strtok(NULL, ":")) != NULL)
    {
        path_index++;
    }

    while (1)
    {
        _print_str("");
        input_size = getline(&input_line, &line_length, stdin);
        if (input_size == -1)
            break;

        remove_newline(input_line);
        tokenize_args(arguments, input_line);
        if (arguments[0] == NULL)
            continue;

        if (strcmp(arguments[0], exit_command) == 0)
            break;
        if (strcmp(arguments[0], environment) == 0)
            print_env(envp);

        executable_path = find_the_path(arguments[0], search_paths);
        if (executable_path != NULL)
        {
            child_pid = fork();

            if (child_pid < 0)
            {
                perror("Process execution failed");
                continue;
            }

            else if (child_pid == 0)
            {
                execve(executable_path, arguments, envp);
                perror("./shell");
                _exit(EXIT_FAILURE);
            }
            wait(NULL);
        }
    }

    free(input_line);
    return (0);
}
