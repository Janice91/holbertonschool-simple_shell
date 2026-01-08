#include "shell.h"

int execve_cmd(char **cmd, char *prog, int line)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0)
    {
        execve(cmd[0], cmd, environ);
        perror(prog);
        exit(127);
    }
    else
        waitpid(pid, &status, 0);

    return (status);
}
