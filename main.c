#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - entry point for the simple shell
 * Return: 0 on success
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("($) ");

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            printf("\n");
            break;
        }

        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (line[0] == '\0')
            continue;

        execute_command(line);
    }

    free(line);
    return (0);
}
