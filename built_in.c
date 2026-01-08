#include "shell.h"

int env_builtin(char **cmd)
{
    int i, j;

    if (_strcmp(cmd[0], "env") != 0 || cmd[1] != NULL)
        return (0);

    for (i = 0; environ[i]; i++)
    {
        for (j = 0; environ[i][j]; j++)
            _putchar(environ[i][j]);
        _putchar('\n');
    }
    return (1);
}

int exit_builtin(char **cmd, char *prog, int line)
{
    int status;

    if (_strcmp(cmd[0], "exit") != 0)
        return (0);

    if (!cmd[1])
        exit(0);

    if (!_atoi(cmd[1]))
    {
        print_exit_illegal(prog, line, cmd[1]);
        exit(2);
    }

    status = _atoi(cmd[1]) % 256;
    exit(status);
}
