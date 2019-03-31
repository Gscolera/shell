#include "shell.h"

void	shell_scroll_input(t_shell *sh, t_reader *rd, int key)
{
	register int	i;

	i = -1;
	if (key == KEYUP && rd->hc == 0)
		return ;
	if (key == KEYDOWN && rd->hc == rd->hm)
		return ;
	ft_strclr(rd->buffer);
	ft_strclr(rd->history[rd->hm]);
	rd->il = 0;
	rd->hc = (key == KEYUP) ? rd->hc - 1 : rd->hc + 1;
	ft_strcpy(rd->buffer, rd->history[rd->hc]);
	ft_strclr(rd->history[rd->hm]);
	shell_mvch(sh, rd);
	TERM_ACTION(CD);
	while (rd->buffer[++i])
		shell_insert_char(sh, rd, rd->buffer[i]);
	ft_strclr(rd->buffer);
}

