#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Environnement global */
extern char **environ;

/* Prototype */
void execute_command(char *line);

#endif

