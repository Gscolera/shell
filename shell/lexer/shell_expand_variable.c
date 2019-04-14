/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expand_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:34:16 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/13 20:15:14 by gscolera         ###   ########.fr       */
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

char			*shell_delete_var_name(char *string, int i)
{
	while (string[i] && string[i] != ' ' && !QUOTE(string[i]))
		ft_delete_char(string, i);
	return (string);
}

char			*shell_expand_variable(t_shell *sh, char *string, size_t i)
{
	char	*expanded;
	char	*value;
	size_t	j;
	size_t	varlen;

	varlen = shell_count_varlen(&string[i + 1]);
	if (!(value = shell_getenv(sh->env, &string[i + 1], varlen++)))
		return (shell_delete_var_name(string, i));
	expanded = ft_strnew(ft_strlen(string) - varlen + ft_strlen(value));
	if (!expanded)
		shell_close(sh, ft_perror("shell", "malloc error"));
	j = 0;
	while (j < i)
	{
		expanded[j] = string[j];
		j++;
	}
	while (value && *value)
		expanded[j++] = *(value++);
	i += varlen;
	while (string[i])
		expanded[j++] = string[i++];
	ft_strdel(&string);
	return (expanded);
}
