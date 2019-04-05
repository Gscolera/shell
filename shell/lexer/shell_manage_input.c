#include "shell.h"

void	shell_manage_input(t_shell *sh)
{
	sh->input = shell_expand_string(sh, sh->input);
	shell_get_commands(sh, sh->input);
}

