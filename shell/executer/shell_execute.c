/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:55:22 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/04 22:09:32 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_next_command(t_shell *sh)
{
	t_command *tmp;

	tmp = sh->cmd->next;
	ft_strdel(&sh->cmd->line);
	free_strings(sh->cmd->argv);
	ft_memdel((void **)&sh->cmd);
	sh->cmd = tmp;
}

void	shell_execute(t_shell *sh)
{
	ft_putchar('\n');
	ft_printf("%s\n", sh->input);
/*	while (sh->cmd)
	{
		ft_printf("%s\n", sh->cmd->line);
		shell_next_command(sh);
	}*/
	ft_strdel(&sh->input);
}
