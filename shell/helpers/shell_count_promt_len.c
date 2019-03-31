#include "shell.h"

void		shell_count_promt_len(t_settings *settings, char *promt)
{
	register int	i;
	register bool	stat;

	i = 0;
	settings->promt_len = 0;
	stat = true;
	while (promt[i])
	{
		if (promt[i] == '{')
			stat = false;
		else if (promt[i] == '}')
			stat = true;
		else if (stat == true)
			settings->promt_len++;
		i++;
	}
}
