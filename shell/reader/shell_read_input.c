/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:52 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 12:31:21 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		shell_insert_char(t_shell *sh, t_reader *rd, char c)
{
	if (rd->il == rd->history->size - 2)
	{
		rd->history->data = (char *)ft_realloc(rd->history->data,
							rd->history->size, rd->history->size + BUFF_SIZE);
		if (!rd->history->data)
			shell_close(sh, ft_perror("shell", "memory allocation error"));
		rd->history->size += BUFF_SIZE;
	}
	ft_insert_char(rd->history->data, c, rd->ic);
	TERM_ACTION(SAVEC);
	ft_putstr(&rd->history->data[rd->ic]);
	TERM_ACTION(RSRC);
	rd->ic++;
	rd->il++;
	if (rd->crs.x < g_window_size.x - 1)
	{
		TERM_ACTION(RIGHT);
		rd->crs.x++;
	}
	else
	{
		rd->crs.x = 0;
		rd->crs.y++;
		TERM_ACTION(DOWN);
	}
}

static void	shell_parse_buffer(t_shell *sh, t_reader *rd, char *buffer)
{
	while (*buffer)
	{
		if (ft_isprint(*buffer))
		{
			shell_insert_char(sh, rd, *buffer);
			rd->buffptr = rd->history;
		}
		else
		{
			shell_parse_events(sh, rd, buffer);
			break ;
		}
		buffer++;
	}
}

static void	shell_print_promt(t_shell *sh)
{
	sh->rd.ic = 0;
	sh->rd.il = 0;
	sh->rd.promt = ft_strdup(sh->settings.promt);
	sh->rd.promt = shell_expand_string(sh, sh->rd.promt);
	shell_delete_characters(sh->rd.promt, "\"\'");
	ft_printf(sh->rd.promt);
	shell_get_cursor_position(&sh->rd.home);
	sh->rd.crs = sh->rd.home;
}

void		shell_read_input(t_shell *sh, t_reader *rd)
{
	tcsetattr(0, TCSANOW, &sh->settings.term_shell);
	shell_print_promt(sh);
	shell_create_history_list(sh, rd);
	g_flags |= READING;
	while (g_flags & READING)
	{
		ft_strclr(rd->buffer);
		read(fileno(stdin), rd->buffer, LINE_MAX);
		shell_parse_buffer(sh, rd, rd->buffer);
		if (g_flags & SHELL_SIGINT)
		{
			rd->buffptr = rd->history;
			ft_strclr(rd->buffptr->data);
			TERM_ACTION(DOWN);
			shell_print_promt(sh);
			g_flags &= ~SHELL_SIGINT;
		}
	}
	sh->input = ft_strtrim(rd->history->data);
	ft_strdel(&sh->rd.promt);
	tcsetattr(0, TCSANOW, &sh->settings.term_default);
	TERM_ACTION(DOWN);
}
