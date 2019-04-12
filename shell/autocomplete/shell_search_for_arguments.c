/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_search_for_arguments.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:52:59 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 15:33:35 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_delete_path_from_input(t_shell *sh, char *path)
{
	while (*path)
	{
		ft_delete_char(sh->input, 0);
		path++;
	}
}

static void	shell_choose_argument(t_shell *sh)
{
	if (!sh->cmp_list)
		return ;
	else if (!sh->cmp_list->next)
		shell_accept_option(sh, sh->cmp_list);
	else
	{
		g_flags |= CHOOSING;
		shell_choose_option(sh, sh->cmp_list);
	}
}

static char	*shell_get_arg_path(t_shell *sh)
{
	char *path;

	if (!sh->input)
		path = shell_get_current_path();
	else
	{
		path = shell_check_path(sh, sh->input);
		if (!path)
			path = shell_extract_path(sh->input);
		if (path)
			shell_delete_path_from_input(sh, path);
		else
			path = shell_get_current_path();
	}
	return (path);
}

void		shell_search_for_argument(t_shell *sh)
{
	char	*path;
	DIR		*dir;

	path = shell_get_arg_path(sh);
	dir = opendir(path);
	if (dir)
	{
		if (ft_strnequ(sh->rd.history->data, "cd ", 3))
			g_flags |= ONLYDIR;
		shell_search_for_options(sh, dir);
		closedir(dir);
		shell_choose_argument(sh);
	}
	ft_strdel(&path);
}
