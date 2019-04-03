#include "shell.h"

bool	shell_quote(char *c, char *start)
{
	return (*c == '\'' && (c == start || *(c - 1) != '\\'));
}

bool	shell_dquote(char *c, char *start)
{
	return (*c == '\"' && (c == start || *(c - 1) != '\\'));
}

bool	shell_bquote(char *c, char *start)
{
	return (*c == '`' && (c == start || *(c - 1) != '\\'));
}
