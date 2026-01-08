#include "shell.h"

/**
 * execute - execute a command
 * @line: line from stdin
 * @prog: program name (argv[0])
 * @line_count: current line number
 */
void execute(char *line, char *prog, int line_count)
{
	char *cmd[2];

	/* supprime le \n final */
	if (line[0] == '\0')
		return;

	if (line[0] == '\n')
		return;

	line[strcspn(line, "\n")] = 0;

	cmd[0] = line;
	cmd[1] = NULL;

	if (execve_cmd(cmd, prog, line_count) == -1)
		print_not_found(prog, line_count, line);
}
