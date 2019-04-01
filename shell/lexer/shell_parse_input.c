#include "shell.h"

void	shell_parse_input(t_shell *sh, t_reader *rd)
{
	ft_printf("\n%s\n", rd->history->data);
	if (ft_strequ(rd->history->data, "exit"))
		shell_close(sh, EXIT_SUCCESS);
}
