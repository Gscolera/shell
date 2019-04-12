/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_automoplete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:52:45 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:52:49 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		shell_close_autocomplete(t_shell *sh)
{
	t_cmplt	*tmp;

	while (sh->cmp_list)
	{
		tmp = sh->cmp_list->next;
		ft_strdel(&sh->cmp_list->option);
		free(sh->cmp_list);
		sh->cmp_list = tmp;
	}
	sh->cmp_list = NULL;
	sh->act_list = NULL;
	ft_strdel(&sh->input);
	g_flags &= ~(CHOOSING | ONLYDIR | ONLYEXEC);
	sh->options.len = 0;
	sh->options.max_len = 0;
	sh->options.count = 0;
	TERM_ACTION(CD);
}

void		shell_accept_option(t_shell *sh, t_cmplt *list)
{
	int		i;

	i = ft_strlen(sh->input);
	while (list->option[i])
		shell_insert_char(sh, &sh->rd, list->option[i++]);
}

void		shell_autocomplete(t_shell *sh)
{
	char	*cmplt_fragment;

	shell_mvce(sh, &sh->rd);
	cmplt_fragment = ft_strrchr(sh->rd.history->data, ' ');
	if (cmplt_fragment)
	{
		if (!*(cmplt_fragment + 1))
			sh->input = NULL;
		else if (!(sh->input = ft_strdup(++cmplt_fragment)))
			shell_close(sh, ft_perror("shell", "malloc error"));
		shell_search_for_argument(sh);
	}
	else if (!cmplt_fragment)
	{
		if (!(sh->input = ft_strdup(sh->rd.history->data)))
			shell_close(sh, ft_perror("shell", "malloc error"));
		shell_search_for_command(sh);
	}
	shell_close_autocomplete(sh);
}
