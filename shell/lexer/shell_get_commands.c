#include "shell.h"

static void 	shell_get_next_command(t_shell *sh, char *input, int len)
{
	char			*new_cmd;

	if (len == 0 && input[0] == ';')
		return ;
	new_cmd = ft_strnew(len + 1);
	if (!new_cmd)
		shell_close(sh, ft_perror("shell", "malloc error"));
	ft_strncpy(new_cmd, input, len);
	ft_strtrim(new_cmd);
	if (!sh->cmd)
	{
		sh->cmd = strings_allocate(1);
		sh->cmd[0] = new_cmd;
	}
	else
		string_add(&sh->cmd, new_cmd);
}

void		shell_get_commands(t_shell *sh, char *input)
{
	register int	i;

	i = 0;
	while (input[++i])
	{
		if (QUOTE(input[i]))
			shell_manage_quote(sh, input, i);
		else if (input[i] == ';' && NQT(sh->flags))
		{
			ft_delete_char(input, i);
			shell_get_next_command(sh, input, i);
			input = &input[i];
			i = -1;
		}
	}
	if (i > 1)
		shell_get_next_command(sh, input, i);
}
