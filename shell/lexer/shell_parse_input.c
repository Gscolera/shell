#include "shell.h"

void	shell_parse_input(t_shell *sh, t_reader *rd)
{
	ft_printf("\n%s\n", rd->history[rd->hm]);
	if (ft_strequ(rd->history[rd->hm], "exit"))
		shell_close(sh, EXIT_SUCCESS);
	rd->hc = ++rd->hm;
}
