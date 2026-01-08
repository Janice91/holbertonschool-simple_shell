#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        /* Affiche le prompt */
        printf("#cisfun$ ");
        fflush(stdout);

        /* Lit la ligne de commande */
        nread = getline(&line, &len, stdin);
        if (nread == -1) /* Ctrl+D */
        {
            printf("\n");
            break;
        }

        /* Supprime le \n de la fin */
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        /* Si la ligne est vide, on continue */
        if (line[0] == '\0')
            continue;

        /* Exécute la commande */
        if (execve(line, NULL, environ) == -1)
            perror("./shell");
    }

    free(line);
    return 0;
}

