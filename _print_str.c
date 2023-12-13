#include "shell.h"

/**
 * _print_str - function that calls the _putchar
 * @string: characters passed
 * Return: nothing
 */
void _print_str(char *string)
{
    while (*string != '\0')
    {
        _putchar(*string);
        string++;
    }
}
