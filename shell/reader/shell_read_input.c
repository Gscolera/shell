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
	if (rd->crs.x < sh->settings.window_size.x - 1)
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

static void	shell_expand_promt(t_shell *sh)
{
	char *promt;

	promt = ft_strdup(sh->settings.promt);
	promt = shell_expand_string(sh, promt);
	shell_delete_characters(promt, "\"\'");
	shell_count_promt_len(&sh->settings, promt);
	sh->rd.crs.x = sh->settings.promt_len;
	ft_printf(promt);
	ft_strdel(&promt);
}

void	shell_read_input(t_shell *sh, t_reader *rd)
{
	rd->ic = 0;
	rd->il = 0;
	rd->crs.y = 0;
	shell_create_history_list(sh, rd);
	shell_expand_promt(sh);
	sh->flags |= READING;	
	while (sh->flags & READING)
	{
		ft_strclr(rd->buffer);
		read(fileno(stdin), rd->buffer, LINE_MAX);
		shell_parse_buffer(sh, rd, rd->buffer);
	}
	sh->input = ft_strdup(rd->history->data);
}
