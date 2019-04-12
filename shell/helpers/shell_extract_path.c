/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_extract_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:53:38 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:39 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*shell_extract_path(char *input)
{
	register int	i;

	i = ft_strlen(input);
	if (!i || !input)
		return (NULL);
	while (i > 0 && input[--i] != '/')
		NULL;
	if (i == 0 && input[i] != '/')
		return (NULL);
	return (ft_strsub(input, 0, ++i));
}
