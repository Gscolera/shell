#include "shell.h"

char	*shell_get_value(char **array, char *var)
{
	size_t	len;
	size_t	i;

	if (!array || !var || !(len = ft_strlen(var)))
		return (NULL);
	i = -1;
	while (array[++i])
	{
		if (ft_strnequ(array[i], var, len))
		{
			while (array[i][len] && array[i][len] != '=')
				len++;
			return (&array[i][++len]);
		}
	}
	return (NULL);
}
