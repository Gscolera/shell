/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:55:03 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:55:04 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_free_history_buffer(t_reader *rd)
{
	while (rd->history)
	{
		rd->buffptr = rd->history->next;
		ft_strdel(&rd->history->data);
		ft_memdel((void **)&rd->history);
		rd->history = rd->buffptr;
	}
}

void		shell_close(t_shell *sh, int exit_code)
{
	tcsetattr(fileno(stdin), TCSANOW, &sh->settings.term_default);
	if (sh->env)
		free_strings(sh->env);
	if (sh->rd.history)
		shell_free_history_buffer(&sh->rd);
	if (sh->input)
		ft_strdel(&sh->input);
	ft_putstr("\033]2;Terminal\007");
	exit(exit_code);
}
