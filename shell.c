#include "shell.h"
#include <sys/wait.h> /* Pour wait */

/**
 * execute_command - executes a single-word command
 * @line: command to execute
 */
void execute_command(char *line)
{
    pid_t pid;
    int status;
    char *argv[2]; /* On déclare le tableau sans l'initialiser ici */

    argv[0] = line; /* On remplit après */
    argv[1] = NULL;

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
        wait(&status); /* wait nécessite sys/wait.h */
    }
}
