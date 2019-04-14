/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:55:22 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 20:48:00 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_next_command(t_shell *sh)
{
	t_command *tmp;

	tmp = sh->cmd_list;
	sh->cmd_list = sh->cmd_list->next;
	free_strings(tmp->argv);
	ft_strdel(&tmp->cmd);
	free(tmp);
}

static bool	shell_execute_builtin(t_shell *sh, char *bin)
{
	if (ft_strequ(bin, "exit"))
		shell_close(sh, EXIT_SUCCESS);
	else if (ft_strequ(bin, "cd"))
		shell_change_dir(sh, sh->cmd_list->argv);
	else if (ft_strequ(bin, "setenv"))
		shell_setenv(sh, sh->cmd_list->argv);
	else if (ft_strequ(bin, "unsetenv"))
		shell_unsetenv(sh, sh->cmd_list->argv);
	else if (ft_strequ(bin, "echo"))
		shell_echo(sh->cmd_list->argv);
	else if (ft_strequ(bin, "env"))
		print_strings(sh->env);
	else
		return (0);
	return (1);
}

void		shell_execute(t_shell *sh)
{
	while (sh->cmd_list)
	{
		if (!shell_execute_builtin(sh, sh->cmd_list->argv[0]))
		{
			shell_find_binary(sh, sh->cmd_list->argv);
			shell_run_binary(sh);
		}
		shell_next_command(sh);
		ft_strdel(&sh->binary);
	}
}
