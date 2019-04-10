#include "libft.h"
#include <stdio.h>

bool	string_add(char ***string, char *str)
{
	char	**new;
	char	**ptr;
	int		i;

	ptr = *string;
	new = strings_allocate(count_strings(ptr) + 1);
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
		if (ft_strnequ(string[i], srch, length))
			return (string[i]);
		i++;
	}
	return (NULL);

}
