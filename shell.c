#include "shell.h"


int main(int ac, char **av, char **envp)
{
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char *args[MAX_ARGS];
  char *path[MAX_ARGS];
  pid_t pid;
  char *executable_path;

  
  (void)ac;
  (void)av;

  while(1)
    {
      printf("$");

      read = getline(&line, &len, stdin);
      if (read == -1)
	break;

      
      executable_path = find_path(args[0], path);
      if (executable_path != NULL)
	{
	  pid = fork();

	  if (pid < 0)
	    {
	      perror("Process execution failed");
	      continue;
	    }

	  else if (pid == 0)
	    {
	      execve(executable_path, args, envp);
	      perror("./shell");
	      _exit(EXIT_FAILURE);
	    }
	  wait(NULL);
	}
    }
  free(line);
  return (0);
}
