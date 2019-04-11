#include "shell.h"

static void		shell_lsearch(t_shell *sh)
{
	char			*path;
	int				i;
	DIR				*dir;

	if (!(path = shell_check_path(sh, sh->input)))
		path = shell_extract_path(sh->input);
	i = -1;
	while (path[++i])
		ft_delete_char(sh->input, 0);
	dir = opendir(path);
	if (dir)
	{
		shell_search_for_options(sh, dir);
		closedir(dir);
	}
	free(path);
}

static void	shell_gsearch(t_shell *sh)
{
	DIR	*dir;
	int	i;

	i = -1;
	shell_search_builtin(sh);
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
	free_strings(sh->path);
}

void		shell_search_for_command(t_shell *sh)
{
	t_cmplt *tmp;

	sh->flags |= ONLYEXEC;
	(shell_is_path(sh->input)) ? shell_lsearch(sh) : shell_gsearch(sh);
	if (!sh->cmp_list)
		return ;
	else if (!sh->cmp_list->next)
		shell_accept_option(sh, sh->cmp_list);
	else
	{
		sh->flags |= CHOOSING;
		shell_choose_option(sh, sh->cmp_list);
	}
}
