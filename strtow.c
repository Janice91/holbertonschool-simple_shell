#include "shell.h"

char **strtow(char *str, char *delim)
{
    int i, j, k, count = 0;
    char **words;

    if (!str || !*str)
        return (NULL);

    for (i = 0; str[i]; i++)
        if (str[i] != delim[0] && (i == 0 || str[i - 1] == delim[0]))
            count++;

    words = malloc((count + 1) * sizeof(char *));
    if (!words)
        return (NULL);

    for (i = 0, k = 0; str[i]; i++)
    {
        if (str[i] != delim[0])
        {
            j = i;
            while (str[i] && str[i] != delim[0])
                i++;
            words[k] = malloc(i - j + 1);
            if (!words[k])
                return (NULL);
            strncpy(words[k], str + j, i - j);
            words[k][i - j] = '\0';
            k++;
        }
    }
    words[k] = NULL;
    return (words);
}
