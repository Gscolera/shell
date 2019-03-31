#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new;

	if (!ptr || !(new = ft_memalloc(new_size)))
		return (NULL);
	new = ft_memcpy(new, ptr, old_size);
	ft_memdel(&ptr);
	return (new);
}
