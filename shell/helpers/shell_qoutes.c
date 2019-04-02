#include "shell.h"

bool	shell_squote(char *line, int i)
{
	return (line[i] == '\'' && (i == 0 || line[i - 1] != '\\'));
}

bool	shell_dquote(char *line, int i)
{
	return (line[i] == '\"' && (i == 0 || line[i - 1] != '\\'));
}
