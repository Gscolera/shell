/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:44:20 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:44:34 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
