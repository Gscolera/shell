#include "shell.h"

void		shell_insert_char(t_shell *sh, t_reader *rd, char c)
{
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
		if (ft_isprint(*buffer) && rd->il < LINE_MAX)
		{
			shell_insert_char(sh, rd, *buffer);
			rd->buffptr = rd->history;
		}
		else
			buffer += shell_parse_events(sh, rd, buffer);
		buffer++;
	}
}

void	shell_read_input(t_shell *sh, t_reader *rd)
{
	shell_print_promt(sh);
	shell_create_history_list(sh, rd);
	while (sh->flags & READING)
	{
		ft_strclr(rd->buffer);
		read(fileno(stdin), rd->buffer, LINE_MAX);
		shell_parse_buffer(sh, rd, rd->buffer);
	}
}
