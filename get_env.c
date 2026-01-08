#include "shell.h"

char *_getenv(const char *name)
{
    int i, nlen;

    nlen = strlen(name);
    for (i = 0; environ && environ[i]; i++)
    {
        if (_strncmp(environ[i], name, nlen) == 0 && environ[i][nlen] == '=')
            return (environ[i] + nlen + 1);
    }
    return (NULL);
}
