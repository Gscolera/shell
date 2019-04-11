#include "shell.h"

bool	shell_is_path(char *input)
{
	return (input[0] == '.' || input[0] == '/');
}
