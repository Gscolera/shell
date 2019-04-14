/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_bck_i_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:31:26 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 19:48:21 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_search_in_history(t_shell *sh, t_reader *rd, t_request *rqst)
{
	size_t	i;

	while (rd->buffptr && !(g_flags & MATCH))
	{
		if (ft_strstr(rd->buffptr->data, rqst->line))
		{
			i = -1;
			g_flags |= MATCH;
			shell_clear_input(sh, rd);
			while (rd->buffptr->data[++i])
				shell_insert_char(sh, rd, rd->buffptr->data[i]);
		}
		rd->buffptr = rd->buffptr->next;
	}
	rd->buffptr = rd->history;
}

static void	shell_create_request(t_shell *sh, t_reader *rd, t_request *request)
{
	size_t	i;

	i = -1;
	while (rd->buffer[++i])
	{
		if (ft_isprint(rd->buffer[i]) && rd->crs.x < g_window_size.x)
		{
			request->line[request->pos++] = rd->buffer[i];
			ft_printf(&request->line[request->pos - 1]);
			rd->crs.x++;
		}
		else if (rd->buffer[i] == KEYENTER)
			g_flags &= ~(READING | SEARCHING);
		else if (rd->buffer[i] == 127 && request->pos > 0) 
		{
			shell_get_cursor_position(&rd->crs);
			request->line[--request->pos] = 0;
			shell_mvcl(sh, rd);
			TERM_ACTION(CD);
		}
		else if (rd->buffer[i] == 27)
			g_flags &= ~SEARCHING;
	}	
}

static void	shell_print_request_line(t_shell *sh, t_request *request)
{
	sh->rd.buffptr = sh->rd.history;	
	shell_mvcd(sh, &sh->rd);
	if (g_flags & MATCH || !request->pos)
		ft_printf("{magenta}{bold}bck_i_search{eoc}: ");
	else
		ft_printf("{magenta}{bold}failing bck_i_search{eoc}: ");
	ft_printf(request->line);
	shell_get_cursor_position(&sh->rd.crs);
	shell_mvch(sh, &sh->rd);
}

void		shell_bck_i_search(t_shell *sh, t_reader *rd)
{
	t_request	request;
	
	ft_memset(&request, 0, sizeof(t_request));
	g_flags |= SEARCHING;
	while (g_flags & SEARCHING)
	{	
		ft_strclr(rd->buffer);
		shell_print_request_line(sh, &request);
		read(fileno(stdin), rd->buffer, LINE_MAX);	
		shell_create_request(sh, rd, &request);
		shell_search_in_history(sh, rd, &request);
	}
	shell_mvch(sh, rd);
	shell_mvce(sh, rd);
	TERM_ACTION(CD);
}
