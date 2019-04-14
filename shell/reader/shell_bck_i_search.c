/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_bck_i_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:31:26 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 13:47:47 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_search_in_history(sh, t_reader *rd, t_request *request)
{
	while (rd->buffptr)
	{
		if (ft_ )
	}

}

static void	shell_create_request(t_shell *sh, t_reader *rd, t_request *request)
{
	size_t	i;

	i = -1;
	while (rd->buffer[++i])
	{
		if (ft_isprint(rd->buffer[i]))
		{
			request->line[request->pos++] = rd->buffer[i];
			ft_printf(&request->line[request->pos - 1]);
		}
		else if (rd->buffer[i] == KEYENTER)
			g_flags &= ~(READING | SEARCHING);
		else if (rd->buffer[i] == 127 && request->crs != request->start_request) 
		{
			request->line[--request->pos] = 0;

		}
		else
			g_flags &= ~SEARCHING;
	}	
}

void		shell_bck_i_search(t_shell *sh, t_reader *rd)
{
	t_request	request;
	
	ft_memset(&request, 0, sizeof(t_request));
	g_flags |= SEARCHING;
	rd->buffptr = rd->history;	
	shell_mvcd(sh ,rd);
	shell_get_cursor_position(&request->home);
	ft_printf("{magenta}{bold}bck_i_search{eoc}: ");
	while (g_flags & SEARCHING)
	{	
		ft_strclr(rd->buffer);
		read(fileno(stdin), rd->buffer, LINE_MAX);
		shell_create_request(sh, rd, &request);
		shell_search_in_history(sh, rd &request);
	}
	shell_get_cursor_position(&rd->crs);
	shell_mvch(sh, rd);
	shell_mvce(sh, rd);
	TERM_ACTION(CD);
}
