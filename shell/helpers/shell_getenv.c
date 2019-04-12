/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_getenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:53:53 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:54 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*shell_getenv(char **array, char *var, int len)
{
	size_t	i;

	if (!array || !var)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		if (ft_strnequ(array[i], var, len) && array[i][len] == '=')
			return (&array[i][++len]);
	}
	return (NULL);
}
