/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_search_for_options.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:22:19 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/10 19:37:22 by gscolera         ###   ########.fr       */
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

void	shell_search_for_options(t_shell *sh, DIR *dir)
{
	struct dirent	*sd;
	int				len;

	len = ft_strlen(sh->input);
	while ((sd = readdir(dir)))
	{
		if (ft_strnequ(sd->d_name, sh->input, len))
			shell_add_option(sh, ft_strdup(sd->d_name));
	}
}
