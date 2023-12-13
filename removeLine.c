#include "main.h"

/**
 * remove_newline - removes newline from the buffer
 * @str: character
 * Return: nothing
 */
void remove_newline(char *str)
{
    char *newline_position = strchr(str, '\n');

    if (newline_position != NULL)
    {
        *newline_position = '\0';
    }
}
