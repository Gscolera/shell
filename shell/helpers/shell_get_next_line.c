#include "shell.h"

void		shell_get_next_line(t_shell *sh, int fd)
{
	char	*bufptr;

	bufptr = sh->rd.buffer;
	ft_strclr(bufptr);
	while (true)
	{
		if (!read(fd, bufptr, 1) || *bufptr == '\n')
		{
			if (*bufptr)
				*bufptr = '\0';
			return ;
		}
		bufptr++;
		if (sh->rd.buffer - bufptr == LINE_MAX - 2)
			return ;
	}
}	
