#include "libft.h"

char	ft_getchar(int fd)
{
	char buf[0];

	read(fd, buf, 1);
	return (buf[0]);
}
