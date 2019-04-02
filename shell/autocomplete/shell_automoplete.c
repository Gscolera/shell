#include "shell.h"

void	shell_autocomplete(t_shell *sh, t_reader *rd)
{
	t_cmplt			list;
	register int	i;

	ft_memset(&list, 0, sizeof(t_cmplt));
	if (ft_strchr(rd->history->data, ' '))
	{
		i = rd->il;
		while (rd->history->data[i] != ' ')
			i--;
		i++;
		list.line = ft_strsub(rd->history->data, i, rd->il - i);
		shell_arg_srch(sh, rd, &list);
	}
	else
	{
		list.line = ft_strdup(rd->history->data);
		shell_cmd_srch(sh, rd, &list);
	}
	ft_strdel(&list.line);
}
