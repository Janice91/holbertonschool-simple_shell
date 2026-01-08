#include "shell.h"

void free_cmd(char **cmd)
{
    int i;

    if (!cmd)
        return;
    for (i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
}
