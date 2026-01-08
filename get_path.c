#include "shell.h"

char *get_path(char **cmd)
{
    char *env, **dirs, *full;
    int i;
    struct stat st;

    env = _getenv("PATH");
    if (!env)
        return (NULL);

    dirs = strtow(env, ":");
    if (!dirs)
        return (NULL);

    for (i = 0; dirs[i]; i++)
    {
        full = malloc(strlen(dirs[i]) + strlen(cmd[0]) + 2);
        sprintf(full, "%s/%s", dirs[i], cmd[0]);
        if (stat(full, &st) == 0)
        {
            free_cmd(dirs);
            return (full);
        }
        free(full);
    }
    free_cmd(dirs);
    return (NULL);
}
