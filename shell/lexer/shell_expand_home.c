/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expand_home.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:20 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 19:17:38 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*shell_expand_home(t_shell *sh, char *string, int i)
{
	char	*value;
	char	*expanded;
	int		j;

	value = shell_getenv(sh->env, "HOME", 4);
	if (!value)
	{
		ft_delete_char(string, i);
		return (string);
	}
	expanded = ft_strnew(ft_strlen(string) + ft_strlen(value) - 1);
	if (!expanded)
		shell_close(sh, ft_perror("shell", "malloc error"));
	j = -1;
	while (++j < i)
		expanded[j] = string[j];
	while (value && *value)
		expanded[j++] = *(value++);
	i += 1;
	while (string[i])
		expanded[j++] = string[i++];
	ft_strdel(&string);
	return (expanded);
}
