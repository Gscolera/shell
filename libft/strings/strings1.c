#include "libft.h"
#include <stdio.h>

bool	string_add(char ***string, char *str)
{
	char	**new;
	char	**ptr;
	int		i;

	ptr = *string;
	new = strings_allocate(strings_length(ptr) + 1);
	if (!new)
		return (0);
	i = -1;
	while (ptr[++i])
		new[i] = ptr[i];
	new[i] = ft_strdup(str);
	free(ptr);
	*string = new;
	return (1);
}

bool	string_delete(char ***string, char *str)
{
	char	**new;
	size_t	length;
	size_t	i;
	size_t	j;

	if (!(length = strings_length(string[0])))
		return (0);
	if (!(new = strings_allocate(length - 1)))
		return (0);
	i = 0;
	j = 0;
	while (string[0][j])
	{
		if (ft_strncmp(string[0][j], str, ft_strlen(str)))
			new[i++] = string[0][j++];
		else
		{
			ft_strdel(&string[0][j]);
			j++;
		}
	}
	free(string[0]);
	string[0] = new;
	return (1);
}

char	*string_search(char **string, char *srch)
{
	size_t	i;
	size_t	length;

	i = 0;
	if (!string || !srch)
		return (NULL);
	length = ft_strlen(srch);
	while (string[i])
	{
		if (!ft_strncmp(string[i], srch, length))
			return (string[i]);
		i++;
	}
	return (NULL);

}
