#include "shell.h"

int main() {
    char command[BUFSIZE];
    pid_t pid;

    while (1) {
        display_prompt();

        if (fgets(command, BUFSIZE, stdin) == NULL) {
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            if (execlp(command, command, (char *)NULL) == -1) {
                perror("exec");
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                if (WEXITSTATUS(status) != 0) {
                    fprintf(stderr, "./shell: %s: command not found\n", command);
                }
            } else {
                fprintf(stderr, "./shell: %s: command not found\n", command);
            }
        }
    }

    return 0;
}
