#include "libft.h"

char	*ft_pathcat(char *dir, char *name)
{
	char	*path;
	size_t	length;

	if (!dir || !name)
		return (NULL);
	length = ft_strlen(dir) + ft_strlen(name) + 1;
	if (!(path = ft_strnew(length)))
		return (NULL);
	ft_strcat(path, dir);
	if (path[ft_strlen(path) - 1] != '/')
		ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}
