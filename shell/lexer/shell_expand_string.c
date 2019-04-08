/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expand_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:19:09 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/08 15:15:43 by gscolera         ###   ########.fr       */
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

void		shell_manage_quote(t_shell *sh, char *string, int i)
{
	if (string[i] == '\'' && !(sh->flags & DQT))
	{
		if (sh->flags & SQT)
			sh->flags &= ~SQT;
		else
			sh->flags |= SQT;
	}
	else if (string[i] == '\"' && !(sh->flags & SQT))
	{
		if (sh->flags & DQT)
			sh->flags &= ~DQT;
		else
			sh->flags |= DQT;
	}
}

static char	*shell_manage_special(t_shell *sh, char *string, int i)
{
	if (string[i] == '$')
		string = shell_expand_variable(sh, string, i);
	else if (string[i] == '~' && !(sh->flags & DQT))
		string = shell_expand_home(sh, string, i);
	return (string);
}

char		*shell_expand_string(t_shell *sh, char *string)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (BSLASH(string[i]) && !(sh->flags & SQT))
			ft_delete_char(string, i);
		else if (QUOTE(string[i]) && QUOTE(string[i + 1]) && NQT(sh->flags))
		{
			ft_delete_char(string, i);
			ft_delete_char(string, i--);
		}
		else if (QUOTE(string[i]))
			shell_manage_quote(sh, string, i);
		else if (shell_special(string[i]) && !(sh->flags & SQT))
			string = shell_manage_special(sh, string, i);
	}
	sh->flags &= ~(SQT | DQT);
	return (string);
}
