/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_window_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:53:51 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:52 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_get_window_size(void)
{
	struct winsize w;

	ioctl(fileno(stdin), TIOCGWINSZ, &w);
	g_window_size.x = w.ws_col;
	g_window_size.y = w.ws_row;
}
