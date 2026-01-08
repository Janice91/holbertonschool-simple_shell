#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

int _atoi(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
void _putchar(char c);
void print_number(int n);

int execute_command(char *line);
int execve_cmd(char **cmd, char *prog, int line);
char *get_path(char **cmd);

int env_builtin(char **cmd);
int exit_builtin(char **cmd, char *prog, int line);

void print_perm_denied(char *prog, int line, char *cmd);
void print_not_found(char *prog, int line, char *cmd);
void print_is_dir(char *prog, int line, char *cmd);
void print_exit_illegal(char *prog, int line, char *arg);
void print_exit_too_many(char *prog, int line);

#endif
