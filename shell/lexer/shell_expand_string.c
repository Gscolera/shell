/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expand_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:19:09 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 19:19:55 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static bool	shell_special(char c)
{
	return (c == '$' ||
			c == '~' ||
			c == '*' ||
			c == '?');
}

void		shell_manage_quote(char *string, int i)
{
	if (string[i] == '\'' && !(g_flags & DQT))
	{
		if (g_flags & SQT)
			g_flags &= ~SQT;
		else
			g_flags |= SQT;
	}
	else if (string[i] == '\"' && !(g_flags & SQT))
	{
		if (g_flags & DQT)
			g_flags &= ~DQT;
		else
			g_flags |= DQT;
	}
}

static char	*shell_manage_special(t_shell *sh, char *string, int i)
{
	if (string[i] == '$')
		string = shell_expand_variable(sh, string, i);
	else if (string[i] == '~' && !(g_flags & DQT))
		string = shell_expand_home(sh, string, i);
	return (string);
}

char		*shell_expand_string(t_shell *sh, char *string)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (BSLASH(string[i]) && !(g_flags & SQT))
			ft_delete_char(string, i);
		else if (QUOTE(string[i]) && QUOTE(string[i + 1]) && NQT(g_flags))
		{
			ft_delete_char(string, i);
			ft_delete_char(string, i--);
		}
		else if (QUOTE(string[i]))
			shell_manage_quote(string, i);
		else if (shell_special(string[i]) && !(g_flags & SQT))
			string = shell_manage_special(sh, string, i);
	}
	g_flags &= ~(SQT | DQT);
	return (string);
}
