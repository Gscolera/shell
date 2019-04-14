/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_find_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:45:40 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 14:40:05 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		shell_find_binary(t_shell *sh, char **argv)
{
	char	**path;
	int		i;

	if (access(argv[0], FILE_EXISTS))
	{
		path = ft_strsplit(shell_getenv(sh->env, "PATH", 4), ':');
		if (path)
		{
			i = -1;
			while (path[++i] && !sh->binary)
			{
				sh->binary = ft_pathcat(path[i], argv[0]);
				if (access(sh->binary, FILE_EXISTS))
					ft_strdel(&sh->binary);
			}
			free_strings(path);
		}
	}
	else
		sh->binary = ft_strdup(argv[0]);
}
