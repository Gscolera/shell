#include "shell.h"

char	*shell_check_path(t_shell *sh, char *input)
{
	struct stat st;

	if (lstat(input, &st) == -1)
		return (NULL);
	if (input[ft_strlen(input) - 1] != '/' && S_ISDIR(st.st_mode))
		shell_insert_char(sh, &sh->rd, '/');
	return (ft_strdup(input));
}
