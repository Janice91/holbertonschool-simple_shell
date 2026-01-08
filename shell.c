#include "shell.h"

/**
 * execute_command - executes a single-word command
 * @line: command to execute
 */
void execute_command(char *line)
{
    pid_t pid;
    int status;
    char *argv[] = {line, NULL};

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0) /* child process */
    {
        if (execve(line, argv, environ) == -1)
        {
            perror("./hsh");
            _exit(1);
        }
    }
    else /* parent process */
    {
        wait(&status);
    }
}
