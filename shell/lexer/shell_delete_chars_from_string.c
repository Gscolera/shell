#include "shell.h"

void	shell_delete_chars_from_string(char *str, char *dlt)
{
	register int i;
	register int j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (dlt[++j])
		{
			if (str[i] == dlt[j] && (i == 0 || str[i - 1] != '\\'))
			{
				ft_delete_char(str, i);
				j = -1;
			}
		}
	}
}
