#include "libft.h"
#include "ft_printf.h"

char	**strings_allocate(size_t size)
{
	char			**array;

	array = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	return (array);
}

void	free_strings(char **string)
{
	size_t	i;

	if (string)
	{
		i = 0;
		while (string[i])
			ft_strdel(&string[i++]);
		free(string);
	}
}

void	print_strings(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putendl(str[i]);
}

size_t	count_strings(char **strings)
{
	size_t	length;

	length = 0;
	while (strings[length])
		length++;
	return (length);
}

char	**copy_strings(char **strings)
{
	char	**new;
	size_t	i;
	size_t	length;

	i = 0;
	if (!(length = count_strings(strings)))
		return (NULL);
	new = strings_allocate(length);
	while (i < length)
	{
		new[i] = ft_strdup(strings[i]);
		i++;
	}
	return (new);
}
