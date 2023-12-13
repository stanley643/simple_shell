#ifndef SHELL_H
#define SHELL_H

/** buit-in file headers  */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define MAX_ARGS 11

char *find_path(char *command, char *path[]);

#endif
