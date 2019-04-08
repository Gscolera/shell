/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:27:53 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/08 21:27:14 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		shell_get_next_arg(t_shell *sh, t_command *cmd_list, char *cmd)
{
	char	start;
	int		i;

	i = -1;
	start = *cmd;
	if (QUOTE(start))
	{
		cmd++;
		while (cmd[++i] != start)
			NULL;
		cmd[i] = '\0';
		ft_printf("\n ARGV %s", cmd);
		string_add(&cmd_list->argv, cmd);
	}
	else
	{
		while (cmd[i] && cmd[i] > 32)
			i++;
		cmd[i] == '\0';	
		ft_printf("\n ARGV %s", cmd);
		string_add(&cmd_list->argv, cmd);
	}
}

static void		shell_get_argv(t_shell *sh, t_command *cmd_list, char *cmd)
{
	int	i;

	i = 0;
	while (*cmd)
	{
		while (*cmd && *cmd < 33)
			cmd++;
		shell_get_next_arg(sh, cmd_list, cmd);
		cmd += ft_strlen(cmd_list->argv[i++]) + 1;
	}
	
}

void			shell_split_commands(t_shell *sh, t_command *cmd_list)
{

	while (cmd_list)
	{
		cmd_list->argv = strings_allocate(0);
		if (!cmd_list->argv)
			shell_close(sh, ft_perror("shell", "malloc error"));
		shell_get_argv(sh, cmd_list, cmd_list->cmd);
		cmd_list = cmd_list->next;
	}
}
