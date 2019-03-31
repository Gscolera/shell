#include "shell.h"

static void	shell_read_config_line(t_settings *settings, char *buffptr)
{
	if (ft_strnequ(buffptr, "PROMT=", 6))
		ft_strcpy(settings->promt, buffptr + 6);
	else if (ft_strnequ(buffptr, "HISTORYSIZE=", 12))
		settings->history_buffsize = ft_atoi(buffptr + 12);
}

void		shell_read_config_file(t_shell *sh)
{
	int		fd;
	char	*buffptr;

	if ((fd = open(".shellrc", O_RDONLY)) > 0)
	{
		buffptr = sh->rd.buffer;
		while (true)
		{
			shell_get_next_line(sh, fd);
			if (buffptr[0] == '#' && buffptr[1] == ' ')
				continue ;
			else if (buffptr[0])
				shell_read_config_line(&sh->settings, buffptr);
			else
				break ;
			ft_strclr(buffptr);
		}
		close (fd);
	}
}
