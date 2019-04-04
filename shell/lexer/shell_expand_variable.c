/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expand_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:34:16 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/04 22:25:07 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t	shell_count_varlen(char *ptr)
{
	size_t	varlen;

	varlen = 0;
	while (*ptr && *ptr != ' ' && !QUOTE(*ptr))
	{
		ptr++;
		varlen++;
	}
	return (varlen);
}
void			shell_expand_variable(t_shell *sh, int i)
{
	char	*expanded;
	char	*value;
	size_t	j;
	size_t	varlen;

	varlen = shell_count_varlen(&sh->input[i + 1]);
	value = shell_getenv(sh->env, &sh->input[i + 1], varlen++);
	expanded = ft_strnew(ft_strlen(sh->input) - varlen + ft_strlen(value));
	if (!expanded)
		shell_close(sh, ft_perror("shell", "malloc error"));
	j = 0;
	while (j < i)
	{
		expanded[j] = sh->input[j];
		j++;
	}
	while (*value)
		expanded[j++] = *(value++);
	i += varlen;
	while (sh->input[i])
		expanded[j++] = sh->input[i++];
	ft_strdel(&sh->input);
	sh->input = expanded;
}
