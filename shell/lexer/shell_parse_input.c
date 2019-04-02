#include "shell.h"

static void		shell_validate_input(char *input)
{
	register int 	i;

	i = -1;
	while (input[++i])
	{
		while (shell_squote(input, i) && shell_squote(input, i + 1))
		{
			ft_delete_char(input, i);
			ft_delete_char(input, i + 1);
		}
		while (shell_dquote(input, i) && shell_dquote(input, i + 1))
		{
			ft_delete_char(input, i);
			ft_delete_char(input, i + 1);
		}
		while ((input[i] == ' ' || shell_squote(input, i) || 
				shell_dquote(input, i)) && input[i + 1] == ' ')
		{
			ft_delete_char(input, i + 1);
		}
	}
}

void			shell_parse_input(t_shell *sh, t_reader *rd)
{
	if (ft_strequ(rd->history->data, "exit"))
		shell_close(sh, EXIT_SUCCESS);
	ft_printf("\n%s\n", rd->history->data);
	shell_validate_input(rd->history->data);
	ft_printf("%s\n", rd->history->data);
}
