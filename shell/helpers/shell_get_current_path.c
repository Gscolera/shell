#include "shell.h"

char	*shell_get_current_path(void)
{
	char path[LINE_MAX];

	ft_memset(path, 0, LINE_MAX);
	getcwd(path, LINE_MAX);
	return (ft_strdup(path));
}
