/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_manage_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:28 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 21:30:01 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_check_input(char *input)
{
	while (*input)
	{
		if (*input > 32)
		{
			g_flags |= INPUT_VALID;
			return ;
		}
		input++;
	}
}

void		shell_manage_input(t_shell *sh)
{
	if (*sh->input)
		g_flags |= INPUT_VALID;
	if (g_flags & INPUT_VALID)
	{
		sh->input = shell_expand_string(sh, sh->input);
		shell_split_input(sh, sh->input);
		shell_split_commands(sh, sh->cmd_list);
	}
	else
		ft_strdel(&sh->input);
}
