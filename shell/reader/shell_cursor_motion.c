/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cursor_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:37 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 19:48:16 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_mvcl(t_shell *sh, t_reader *rd)
{
	if (rd->crs.x > 0)
	{
		rd->crs.x--;
		TERM_ACTION(LEFT);
	}
	else
	{
		TERM_ACTION(UPB);
		rd->crs.y--;
		while (rd->crs.x < g_window_size.x - 1)
		{
			TERM_ACTION(RIGHT);
			rd->crs.x++;
		}
	}
	rd->ic--;
}

void	shell_mvcr(t_shell *sh, t_reader *rd)
{
	if (rd->crs.x < g_window_size.x - 1)
	{
		rd->crs.x++;
		TERM_ACTION(RIGHT);
	}
	else
	{
		TERM_ACTION(DOWN);
		rd->crs.x = 0;
		rd->crs.y++;
	}
	rd->ic++;
}

void	shell_mvch(t_shell *sh, t_reader *rd)
{
	while (rd->crs.y > rd->home.y)
	{
		TERM_ACTION(UPB);
		rd->crs.y--;
	}
	while (rd->crs.x != rd->home.x)
	{
		(rd->crs.x > rd->home.x) ? shell_mvcl(sh, rd) : shell_mvcr(sh, rd);
	}
	rd->ic = 0;
}

void	shell_mvce(t_shell *sh, t_reader *rd)
{
	while (rd->ic < rd->il)
		shell_mvcr(sh, rd);
}
