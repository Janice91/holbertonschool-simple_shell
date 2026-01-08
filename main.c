#include "shell.h"

int main(int ac, char **av)
{
    char *line = NULL;
    size_t len = 0;
    int line_count = 0;
    ssize_t nread;

    (void)ac;

    while (1)
    {
        line_count++;
        write(STDOUT_FILENO, "$ ", 2);
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        line[nread - 1] = '\0';
        execute_command(line);
    }

    free(line);
    return (0);
}
