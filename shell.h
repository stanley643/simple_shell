#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define MAX_ARGS 11

char *create_buf(char *buf);
void _print_str(char *c);
int _putchar(char c);
void tokenize_args(char **args_array, char *str);
char *find_the_path(char *command, char *path[]);
void remove_newline(char *str);
void print_env(char **env);

#endif
