#include "shell.h"

int execute_command(char *line)
{
    char **cmd;
    int status;
    pid_t pid;

    cmd = malloc(2 * sizeof(char *));
    if (!cmd)
        return (-1);
    cmd[0] = line;
    cmd[1] = NULL;

    pid = fork();
    if (pid == -1)
    {
        free(cmd);
        return (-1);
    }
    if (pid == 0)
    {
        execve(line, cmd, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    free(cmd);
    return (status);
}
