#include "shell.h"

void		shell_clear_input(t_shell *sh, t_reader *rd)
{
	rd->il = 0;
	rd->ic = 0;
	ft_strclr(rd->history->data);
	shell_mvch(sh, rd);
	TERM_ACTION(CD);
}
