#include "shell.h"

char	*shell_extract_path(char *input)
{
	register int	i;

	i = ft_strlen(input);
	if (!i || !input)
		return (NULL);
	while (i > 0 && input[--i] != '/')
		NULL;
	if (i == 0 && input[i] != '/')
		return (NULL);
	return (ft_strsub(input, 0, ++i));
}
