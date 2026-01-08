#include "shell.h"

/**
 * main - simple shell loop
 * Return: 0 on success
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        /* Affiche le prompt */
        if (isatty(STDIN_FILENO))
            write(1, "($) ", 4);

        nread = getline(&line, &len, stdin);
        if (nread == -1) /* EOF (Ctrl+D) */
        {
            write(1, "\n", 1);
            break;
        }

        /* Supprime le '\n' final */
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        /* Ignore les lignes vides */
        if (line[0] == '\0')
            continue;

        execute_command(line);
    }

    free(line);
    return (0);
}
