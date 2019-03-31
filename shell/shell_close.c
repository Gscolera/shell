#include "shell.h"

void	shell_close(t_shell *sh, int exit_code)
{
	TERM_ACTION(CLR);
	tcsetattr(fileno(stdin), TCSANOW, &sh->settings.term_default);
	if (sh->env)
		free_strings(sh->env);
	if (sh->exec_paths)
		free_strings(sh->exec_paths);
	if (sh->rd.history)
		free_strings(sh->rd.history);
	ft_putstr("\033]2;Terminal\007");
	exit(exit_code);
}
