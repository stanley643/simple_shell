#include "shell.h"
/**
* find_path - an pointer that trys to access the given path using x_OK
* @command: the given input by user
* @path: the array of pointers to the desired executable file
* Return: give NULL value on success
*/
char *find_path(char *command, char *path[])
{
	char exec_path[BUFSIZE];
	int i;

	if (access(command, X_OK) == 0)
		return (command);

	for (i = 0; path[i] != NULL; i++)
	{
		snprintf(exec_path, sizeof(exec_path), "%s/%s", path[i], command);
		if (access(exec_path, X_OK) == 0)
			return (strdup(exec_path));

	}
	return (NULL);
}

void display_prompt() {
    printf("#cisfun$ ");
    fflush(stdout);
}
