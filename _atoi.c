#include "shell.h"

int _atoi(char *s)
{
    int i = 0, sn = 1;
    unsigned int m = 0;

    while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
        i++;
    while ((s[i] < '0' || s[i] > '9') && s[i])
    {
        if (s[i] == '-')
            sn = -sn;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        m = m * 10 + (s[i] - '0');
        i++;
    }
    return (m * sn);
}
