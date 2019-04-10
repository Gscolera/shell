#include "shell.h"

static void	shell_local_search(t_shell *sh)
{
		
}

static void	shell_global_search(t_shell *sh)
{
	DIR	*dir;
	int	i;

	i = -1;
	sh->path = ft_strsplit(shell_getenv(sh->env, "PATH", 4), ':');
	while (sh->path && sh->path[++i])
	{
		dir = opendir(sh->path[i]);
		if (dir)
		{
			shell_search_for_options(sh, dir);
			closedir(dir);
		}
	}
}

void		shell_search_for_command(t_shell *sh)
{
	if (sh->input[0] == '.')
		shell_local_search(sh);
	else
		shell_global_search(sh);
}
