/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:56 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:54:57 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_signal_handler(int signal)
{
	if (signal == SIGWINCH)
		shell_get_window_size();
	if (signal == SIGINT && g_flags & READING)
		g_flags |= SHELL_SIGINT;
}

void		shell_signal_init(void)
{
	signal(SIGWINCH, shell_signal_handler);
	signal(SIGINT, shell_signal_handler);
}
