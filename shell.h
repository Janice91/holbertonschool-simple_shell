#ifndef SHELL_H
#define SHELL_H

extern char **environ;

void execute_command(char *line);
char *find_program(char *cmd);

#endif /* SHELL_H */
