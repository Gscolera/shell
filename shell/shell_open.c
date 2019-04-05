/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:40:11 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/04 21:43:39 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_get_settings(t_shell *sh, t_settings *settings)
{
	struct winsize	w;

	settings->uid = getuid();
	(access(CONFIG_FILE, FILE_EXISTS)) ? NULL : shell_read_config_file(sh);
	shell_get_window_size(&settings->window_size);
	tcgetattr(fileno(stdin), &settings->term_default);
	settings->term_shell = settings->term_default;
	settings->term_shell.c_lflag &= ~(ECHO | ICANON);
	settings->term_shell.c_cc[VMIN] = 1;
	settings->term_shell.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &settings->term_shell);
	if (!settings->promt[0])
		shell_get_promt(settings);
	if (settings->history_buffsize < 1)
		settings->history_buffsize = HISTORY_SIZE;
}

static void	shell_get_escape_sequences(t_reader *rd)
{
	rd->esc[RIGHT] = tgetstr("nd", NULL);
	rd->esc[LEFT] = tgetstr("le", NULL);
 	rd->esc[UPB] = tgetstr("up", NULL);
 	rd->esc[DOWN] = tgetstr("do", NULL);
 	rd->esc[DEL] = tgetstr("dc", NULL);
 	rd->esc[CLR] = tgetstr("cl", NULL);
 	rd->esc[SAVEC] = tgetstr("sc", NULL);
 	rd->esc[RSRC] = tgetstr("rc", NULL);
 	rd->esc[CD] = tgetstr("cd", NULL);
}

static void	shell_allocate_memory(t_shell *sh)
{
	extern char		**environ;

	if (!(sh->env = copy_strings(environ)))
		shell_close(sh, ft_perror("shell error", "unable to copy eviron"));
	if (!(sh->exec_paths = ft_strsplit(shell_getenv(sh->env, "PATH", 4), ':')))
		shell_close(sh, ft_perror("shell error", "unable to get exec paths"));
}

void		shell_open(t_shell *sh)
{
	char	*ttype;
	int		ret;

	ft_memset(sh, 0, sizeof(t_shell));
	shell_get_settings(sh, &sh->settings);	
	shell_allocate_memory(sh);
	ttype = shell_getenv(sh->env, "TERM", 4);
	if (!(ret = tgetent(NULL, ttype) || !(ret = tgetent(NULL, DEFAULT_TERM))))
		shell_close(sh, ft_perror("shell", "terminal type is not defined"));
	else if (ret == -1)
		shell_close(sh, ft_perror("shell", "could not access to termcap database"));
	shell_get_escape_sequences(&sh->rd);
}
