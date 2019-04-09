/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:27:53 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/09 15:51:11 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*shell_fill_buffer(char *buffer, char *cmd, char start)
{
	if (QUOTE(start))
	{
		cmd++;
		while (*cmd != start)
			*(buffer++) = *(cmd++);
	}
	else 
	{
		while (*cmd && !QUOTE(*cmd) && *cmd > 32)
			*(buffer++) = *(cmd++);
	}
	return ((*cmd) ? cmd : cmd - 1);
}

static void		shell_get_argv(t_shell *sh, t_command *cmd_list, char *cmd)
{
	char  buffer[LINE_MAX];

	ft_memset(buffer, 0, LINE_MAX);
	while (*cmd)
	{
		if (*cmd > 32)
		{
			cmd = shell_fill_buffer(buffer, cmd, *cmd);
			string_add(&cmd_list->argv, buffer);
			ft_strclr(buffer);
		}
		cmd++;
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
