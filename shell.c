#include "shell.h"

/**
 * main: the playground for the shell
 * return: return 0;
 *
 */

int main(int ac, char **av)
{
char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    (void)ac;
    (void)av;

    while (1) {
        printf(" ");

        nread = getline(&line, &len, stdin);

        if (nread == -1) {
            printf("\nEnd of input. Exiting.\n");
            break;
        }

        printf("%s", line);
    }

    free(line);

    return 0;
}
