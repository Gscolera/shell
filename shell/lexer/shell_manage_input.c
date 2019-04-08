#include "shell.h"

void	shell_manage_input(t_shell *sh)
{
	sh->input = shell_expand_string(sh, sh->input);
	shell_split_input(sh, sh->input);
	shell_split_commands(sh, sh->cmd_list);
}

