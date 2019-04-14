/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_search_for_options.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:22:19 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/13 19:58:32 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_add_option(t_shell *sh, char *option)
{
	t_cmplt	*new_list;

	if (!option)
		shell_close(sh, ft_perror("shell", "malloc error"));
	if (!(new_list = (t_cmplt *)ft_memalloc(sizeof(t_cmplt))))
		shell_close(sh, ft_perror("shell", "malloc error"));
	new_list->option = option;
	if (!sh->cmp_list)
		sh->cmp_list = new_list;
	else
		shell_insert_option(sh, new_list);
}

void		shell_search_for_options(t_shell *sh, DIR *dir)
{
	struct dirent	*sd;
	size_t			len;
	size_t			opt_len;

	len = ft_strlen(sh->input);
	while ((sd = readdir(dir)))
	{
		if (g_flags & ONLYDIR && !(sd->d_type & DT_DIR))
			continue ;
		if (ft_strnequ(sd->d_name, sh->input, len))
		{
			shell_add_option(sh, ft_strdup(sd->d_name));
			sh->options.count++;
			opt_len = ft_strlen(sd->d_name) + 2;
			sh->options.len += opt_len;
			if (sh->options.max_len < opt_len)
				sh->options.max_len = opt_len;
		}
	}
}

void		shell_search_builtin(t_shell *sh)
{
	int	len;

	len = ft_strlen(sh->input);
	if (ft_strnequ(sh->input, "setenv", len))
		shell_add_option(sh, ft_strdup("setenv"));
	else if (ft_strnequ(sh->input, "unsetenv", len))
		shell_add_option(sh, ft_strdup("unsetenv"));
	else if (ft_strnequ(sh->input, "cd", len))
		shell_add_option(sh, ft_strdup("cd"));
	else if (ft_strnequ(sh->input, "env", len))
		shell_add_option(sh, ft_strdup("env"));
	else if (ft_strnequ(sh->input, "exit", len))
		shell_add_option(sh, ft_strdup("exit"));
	else if (ft_strnequ(sh->input, "echo", len))
		shell_add_option(sh, ft_strdup("echo"));
}
