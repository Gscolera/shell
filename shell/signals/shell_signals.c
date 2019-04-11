#include "shell.h"

static void	shell_sigint(void)
{
	if (sh->pid)
		kill(sh.pid, SIGINT);
}

static void	shell_signal_handler(int signal)
{
	if (signal == SIGINT)
		shell_sigint();
	if (signal == SIGWINCH)
		shell_get_window_size(&sh.settings.window_size);
}

void		shell_signal_init(t_shell *sh)
{
	signal(SIGINT, shell_signal_handler);
	signal(SIGWINCH, shell_signal_handler);
}
