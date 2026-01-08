#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * execute_command - execute a command typed by the user
 * @line: command line
 */
void execute_command(char *line)
{
    pid_t pid;
    int status;
    char *argv[64];
    char *token;
    int i = 0;
    char *path;

    /* Tokenize the input */
    token = strtok(line, " ");
    while (token != NULL && i < 63)
    {
        argv[i++] = token;
        token = strtok(NULL, " ");
    }
    argv[i] = NULL;

    if (argv[0] == NULL)
        return;

    /* Handle exit */
    if (strcmp(argv[0], "exit") == 0)
        exit(0);

    /* Find program in PATH */
    path = find_program(argv[0]);
    if (!path)
    {
        fprintf(stderr, "%s: 1: %s: not found\n", argv[0], argv[0]);
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        free(path);
        return;
    }

    if (pid == 0) /* child */
    {
        if (execve(path, argv, environ) == -1)
        {
            perror(argv[0]);
            free(path);
            exit(1);
        }
    }
    else /* parent */
    {
        waitpid(pid, &status, 0);
        free(path);
    }
}

/**
 * find_program - searches for a program in the PATH
 * @cmd: command name
 * Return: full path or NULL if not found (caller must free)
 */
char *find_program(char *cmd)
{
    char *path_env = getenv("PATH");
    char *path_copy, *dir, *full_path;
    size_t len;

    if (!path_env)
        return NULL;

    path_copy = strdup(path_env);
    if (!path_copy)
        return NULL;

    dir = strtok(path_copy, ":");
    while (dir)
    {
        len = strlen(dir) + strlen(cmd) + 2;
        full_path = malloc(len);
        if (!full_path)
        {
            free(path_copy);
            return NULL;
        }
        snprintf(full_path, len, "%s/%s", dir, cmd);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }
        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
