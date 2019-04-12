/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cursor_motion1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:40 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 15:12:56 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t	shell_count_lines(t_shell *sh, t_reader *rd)
{
	return ((rd->il + sh->settings.promt_len) / g_window_size.x);
}

void			shell_mvcnpw(t_shell *sh, t_reader *rd, long int key)
{
	if (key == SHKEYRIGHT && rd->ic < rd->il)
	{
		while (rd->history->data[rd->ic] && rd->history->data[rd->ic] != ' ')
			shell_mvcr(sh, rd);
		while (rd->history->data[rd->ic] && rd->history->data[rd->ic] == ' ')
			shell_mvcr(sh, rd);
	}
	else if (key == SHKEYLEFT && rd->ic > 0)
	{
		while (rd->ic > 0 && rd->history->data[rd->ic] != ' ')
			shell_mvcl(sh, rd);
		while (rd->ic && rd->history->data[rd->ic] == ' ')
			shell_mvcl(sh, rd);
		while (rd->ic > 0 && rd->history->data[rd->ic - 1] != ' ')
			shell_mvcl(sh, rd);
	}
}

void			shell_mvcnpl(t_shell *sh, t_reader *rd, long int key)
{
	size_t	saved_x;
	size_t	saved_y;

	if (key == SHKEYDOWN && rd->crs.y < shell_count_lines(sh, rd))
	{
		saved_x = rd->crs.x;
		while (rd->crs.x != 0)
			shell_mvcr(sh, rd);
		while (saved_x-- && rd->ic < rd->il)
			shell_mvcr(sh, rd);
	}
	else if (key == SHKEYUP && rd->crs.y > 0)
	{
		saved_x = g_window_size.x - rd->crs.x - 1;
		saved_y = rd->crs.y;
		while (rd->crs.y == saved_y)
			shell_mvcl(sh, rd);
		while (saved_x-- && rd->ic > 0)
			shell_mvcl(sh, rd);
	}
}
