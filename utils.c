#include "shell.h"
#include <stdlib.h>

int _atoi(char *s)
{
    int i = 0, sn = 1;
    unsigned int m = 0;

    while (s[i] >= 9 && s[i] <= 13)
        i++;
    while ((s[i] >= 58 && s[i] <= 126) || (s[i] >= 32 && s[i] <= 47))
    {
        if (s[i] == '-' || s[i] == '+')
            if (s[i] == '-')
                sn = -sn;
        i++;
    }
    if (!(s[i] >= '0' && s[i] <= '9'))
        return (0);
    while (s[i] >= '0' && s[i] <= '9')
    {
        m = m * 10 + s[i] - '0';
        i++;
    }
    return (m * sn);
}

int _isnumber(char *s)
{
    int i = 0;
    if (!s)
        return (0);
    for (; s[i]; i++)
        if (s[i] < '0' || s[i] > '9')
            return (0);
    return (1);
}

int _strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

size_t _strlen(char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

char *_strdup(const char *s)
{
    char *dup;
    int i;

    if (!s)
        return (NULL);
    dup = malloc(_strlen((char *)s) + 1);
    if (!dup)
        return (NULL);
    for (i = 0; s[i]; i++)
        dup[i] = s[i];
    dup[i] = '\0';
    return (dup);
}

char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;
    while (dest[i])
        i++;
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

void free_cmd(char **cmd)
{
    int i;
    if (!cmd)
        return;
    for (i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
}
