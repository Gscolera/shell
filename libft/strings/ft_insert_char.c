#include "libft.h"

void	ft_insert_char(char *string, char c, size_t pos)
{
	size_t	i;

	if (!string || (i = ft_strlen(string)) < pos)
		return ;
	while (i > pos)
	{
		string[i] = string[i - 1];
		i--;
	}
	string[i] = c;
}
