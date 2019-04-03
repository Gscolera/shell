#include "shell.h"

void			shell_parse_input(t_shell *sh)
{
	if (ft_strequ(sh->rd.history->data, "exit"))
		shell_close(sh, EXIT_SUCCESS);
	shell_split_input(sh);
	shell_split_command(sh);
}
