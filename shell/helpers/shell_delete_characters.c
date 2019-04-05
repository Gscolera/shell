#include "shell.h"

void	shell_delete_characters(char *string, char *dlt)
{
	int	i;
	int	j;

	i = -1;
	while (string[++i])
	{
		j = -1;
		while (dlt[++j])
		{
			while (string[i] == dlt[j])
				ft_delete_char(string, i);
		}
	}
}
