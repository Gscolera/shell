/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:49:23 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:50:13 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	string_add(char ***string, char *str)
{
	char	**new;
	char	**ptr;
	int		i;

	ptr = *string;
	new = strings_allocate(count_strings(ptr) + 1);
	if (!new)
		return (0);
	i = -1;
	while (ptr[++i])
		new[i] = ptr[i];
	new[i] = ft_strdup(str);
	free(ptr);
	*string = new;
	return (1);
}

char	*string_search(char **string, char *srch)
{
	size_t	i;
	size_t	length;

	i = 0;
	if (!string || !srch)
		return (NULL);
	length = ft_strlen(srch);
	while (string[i])
	{
		if (ft_strnequ(string[i], srch, length))
			return (string[i]);
		i++;
	}
	return (NULL);
}
