/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:47:00 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/10 13:36:18 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void  shell_print_error(t_shell *sh)
{
	if (!sh->binary)
		ft_perror(sh->cmd_list->argv[0], "command not found");
	else if (access(sh->binary, FILE_EXEC))
		ft_perror(sh->binary, "permission denied");
}

void  shell_run_binary(t_shell *sh)
{
	pid_t	pid;
	int		state;

	if (!sh->binary)
		shell_print_error(sh);
	else
	{
		pid = fork();
		if (pid == -1)
			ft_perror("shell", "fork error");
		if (!pid)
		{
			state = execve(sh->binary, sh->cmd_list->argv, sh->env);
			if (state == -1)
				shell_print_error(sh);
			exit(state);
		}
		else
			waitpid(pid, NULL, 0);
	}
}
