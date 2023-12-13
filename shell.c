#include "shell.h"

/**
 * main: the playground for the shell
 * return: return 0;
 *
 */

int main(int ac, char **av)
{
	char input[BUFSIZE];
	char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;

    (void)ac;
    (void)av;

    while (1) {
        printf(" ");

        nread = getline(&line, &len, stdin);

        if (nread == -1) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';
	
	pid = fork();

	if (pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execlp(input, input, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}
    }

    free(line);

    return 0;
}
