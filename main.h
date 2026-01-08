#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

/* Prototypes des fonctions */
void print_prompt(void);
int read_command(char *cmd, size_t size);
void execute_command(char *cmd, char **envp);

#endif /* MAIN_H */
