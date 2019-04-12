/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_find_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:45:40 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 15:32:45 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_find_binary_global(t_shell *sh, char **argv)
{
	char	**path;
	int		i;

	path = ft_strsplit(shell_getenv(sh->env, "PATH", 4), ':');
	if (!path)
		ft_perror("shell", "variable PATH is not set");
	else
	{
		i = -1;
		while (path[++i] && !sh->binary)
		{
			sh->binary = ft_pathcat(path[i], argv[0]);
			if (access(sh->binary, FILE_EXISTS))
				ft_strdel(&sh->binary);
		}
	}
	free_strings(path);
}

void		shell_find_binary(t_shell *sh, char **argv)
{
	if (access(argv[0], FILE_EXISTS))
		shell_find_binary_global(sh, argv);
	else
		sh->binary = ft_strdup(argv[0]);
}
