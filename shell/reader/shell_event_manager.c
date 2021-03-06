/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_event_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:45 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 19:49:38 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static long	int	shell_get_key(char *buff)
{
	if (!buff[1])
		return (buff[0]);
	if (!buff[2])
		return ((buff[0] << 8) | buff[1]);
	if (!buff[3])
		return ((buff[0] << 16) | (buff[1] << 8) | buff[2]);
	if (!buff[4])
		return ((buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | buff[3]);
	if (!buff[5])
	{
		return (((long)(buff[0]) << 32) | (buff[1] << 24) | (buff[2] << 16) |
				(buff[3] << 8) | buff[4]);
	}
	return (((long)(buff[0]) << 40) | ((long)(buff[1]) << 32) |
			(buff[2] << 24) | (buff[3] << 16) | (buff[4] << 8) | buff[5]);
}

static void		shell_additional_events(t_shell *sh, t_reader *rd, long int key)
{
	if (key == SHKEYRIGHT || key == SHKEYLEFT)
		shell_mvcnpw(sh, rd, key);
	else if (key == SHKEYDOWN || key == SHKEYUP)
		shell_mvcnpl(sh, rd, key);
	else if (key == CNTLD)
		shell_end_of_input(sh, rd);
	else if (key == CNTLR)
		shell_bck_i_search(sh, rd);
}

void			shell_parse_events(t_shell *sh, t_reader *rd, char *buff)
{
	long int	key;

	key = shell_get_key(buff);
	if (key == KEYESC && !(g_flags & CHOOSING))
		shell_close(sh, EXIT_SUCCESS);
	else if (key == KEYLEFT && rd->ic > 0)
		shell_mvcl(sh, rd);
	else if (key == KEYRIGHT && rd->ic < rd->il)
		shell_mvcr(sh, rd);
	else if (key == KEYHOME)
		shell_mvch(sh, rd);
	else if (key == KEYEND)
		shell_mvce(sh, rd);
	else if (key == KEYENTER && !(g_flags & CHOOSING))
		shell_confirm_input(sh, rd);
	else if (key == KEYUP || key == KEYDOWN)
		shell_scroll_history(sh, rd, key);
	else if (key == KEYTAB && rd->il > 0)
		shell_autocomplete(sh);
	else if (key == KEYDEL || key == KEYBS || key == KEYCRTLD)
		shell_delete_char(sh, rd, key);
	else
		shell_additional_events(sh, rd, key);
}
