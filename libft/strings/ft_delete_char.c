#include "libft.h"

void	ft_delete_char(char *string, size_t pos)
{
	if (!string || pos >= ft_strlen(string))
		return ;
	while (string[pos])
	{
		string[pos] = string[pos + 1];
		pos++;
	}
}
