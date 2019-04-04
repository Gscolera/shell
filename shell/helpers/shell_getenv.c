#include "shell.h"

char	*shell_getenv(char **array, char *var, int len)
{
	size_t	i;

	if (!array || !var)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		if (ft_strnequ(array[i], var, len) && array[i][len] == '=')
			return (&array[i][++len]);
	}
	return (NULL);
}
