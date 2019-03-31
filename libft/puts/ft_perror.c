#include "libft.h"

bool	ft_perror(char *cmd, char *error)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("\33[31m", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n\33[0m", 2);
	return (1);
}
