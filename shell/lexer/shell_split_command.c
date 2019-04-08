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

static char		**shell_get_argv(t_shell *sh, t_command *cmd_list, char *cmd)
{
	char	**argv;
	
	argv = strings_allocate(0);
	for (int i = 0; i < 3; i++)
		string_add(&argv, "Hello");
	return (argv);
}

void			shell_split_commands(t_shell *sh, t_command *cmd_list)
{
	while (cmd_list)
	{
		cmd_list->argv = shell_get_argv(sh, cmd_list, cmd_list->cmd);
		cmd_list = cmd_list->next;
	}
}
