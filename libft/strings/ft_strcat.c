/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:40:56 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/10 15:16:08 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!dest)
		return (NULL);
	while (dest[i])
		i++;
	if (!src)
		return (dest);
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
