#include "main.h"

/**
 * tokenize_args - creates an array of command-line arguments
 * by splitting it using space as the delimiter
 * @args_array: array of arguments
 * @str: string to be tokenized
 * Return: nothing
 */
void tokenize_args(char **args_array, char *str)
{
    char *delim = " \t\n";
    int i = 0;

    args_array[i++] = strtok(str, delim);

    while (i < MAX_ARGS - 1 && (args_array[i] = strtok(NULL, delim)) != NULL)
    {
        i++;
    }

    args_array[i] = NULL;
}
