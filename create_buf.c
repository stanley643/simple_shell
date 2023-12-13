#include "main.h"

/**
 * create_buf - Create a buffer object
 * @filename: name of file
 * @buf: parameter
 * Return:  99
 */
char *create_buf(char *buf)
{
    char *new_buf = malloc(sizeof(char) * BUFSIZE);

    if (new_buf == NULL)
    {
        perror("Error creating buffer!");
        exit(EXIT_FAILURE);
    }

    return new_buf;
}
