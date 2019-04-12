/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:46:40 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:46:48 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
