#include "shell.h"

void print_number(int n)
{
    char c;

    if (n / 10)
        print_number(n / 10);
    c = (n % 10) + '0';
    write(STDERR_FILENO, &c, 1);
}

void print_perm_denied(char *prog, int line, char *cmd)
{
    write(STDERR_FILENO, prog, strlen(prog));
    write(STDERR_FILENO, ": ", 2);
    print_number(line);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, strlen(cmd));
    write(STDERR_FILENO, ": Permission denied\n", 20);
}

void print_not_found(char *prog, int line, char *cmd)
{
    write(STDERR_FILENO, prog, strlen(prog));
    write(STDERR_FILENO, ": ", 2);
    print_number(line);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, strlen(cmd));
    write(STDERR_FILENO, ": not found\n", 12);
}

void print_is_dir(char *prog, int line, char *cmd)
{
    write(STDERR_FILENO, prog, strlen(prog));
    write(STDERR_FILENO, ": ", 2);
    print_number(line);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, strlen(cmd));
    write(STDERR_FILENO, ": is a directory\n", 17);
}

void print_exit_illegal(char *prog, int line, char *arg)
{
    write(STDERR_FILENO, prog, strlen(prog));
    write(STDERR_FILENO, ": ", 2);
    print_number(line);
    write(STDERR_FILENO, ": exit: Illegal number: ", 24);
    write(STDERR_FILENO, arg, strlen(arg));
    write(STDERR_FILENO, "\n", 1);
}

void print_exit_too_many(char *prog, int line)
{
    write(STDERR_FILENO, prog, strlen(prog));
    write(STDERR_FILENO, ": ", 2);
    print_number(line);
    write(STDERR_FILENO, ": exit: too many arguments\n", 27);
}
