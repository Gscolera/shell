/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_run_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:47:00 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 21:28:12 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		shell_print_signal(int signal)
{
	if (signal == SIGSEGV)
		ft_perror("shell", "segmentation fault");
	if (signal == SIGBUS)
		ft_perror("shell", "bus error");
}

static void		shell_print_error(t_shell *sh)
{
	if (!sh->binary)
		ft_perror(sh->cmd_list->argv[0], "command not found");
	else if (!access(sh->binary, FILE_EXEC))
		ft_perror(sh->binary, "permission denied");
}

void			shell_run_binary(t_shell *sh)
{
	int		state;
	
	if (!sh->binary)
		shell_print_error(sh);
	else
	{
		sh->pid = fork();
		if (sh->pid == -1)
			ft_perror("shell", "fork error");
		if (!sh->pid)
		{
			if (execve(sh->binary, sh->cmd_list->argv, sh->env) == -1)
				shell_print_error(sh);
			exit(0);
		}
		else
			waitpid(sh->pid, &state, 0);
		(WIFSIGNALED(state)) ? shell_print_signal(WTERMSIG(state)) : 0;
	}
	sh->pid = 0;
}
