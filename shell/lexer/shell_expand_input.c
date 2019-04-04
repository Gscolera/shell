/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expand_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:19:09 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/04 22:04:43 by gscolera         ###   ########.fr       */
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

static void	shell_manage_quote(t_shell *sh, char quote)
{

	if (quote == '\'' && !(sh->flags & DQT))
	{
		if (sh->flags & SQT)
			sh->flags &= ~SQT;
		else
			sh->flags |= SQT;
	}
	else if (quote == '\"' && !(sh->flags & SQT))
	{
		if (sh->flags & DQT)
			sh->flags &= ~DQT;
		else
			sh->flags |= SQT;
	}
}

static void	shell_manage_special(t_shell *sh, int i)
{
	if (sh->input[i] == '$')
		shell_expand_variable(sh, i);

}

void		shell_expand_input(t_shell *sh)
{
	register int	i;

	i = -1;
	while (sh->input[++i])
	{
		if (BSLASH(sh->input[i]) && !(sh->flags & SQT))
			ft_delete_char(sh->input, i);
		else if (QUOTE(sh->input[i]))
			shell_manage_quote(sh, sh->input[i]);
		else if (shell_special(sh->input[i]) && !(sh->flags & SQT))
			shell_manage_special(sh, i);
	}
	sh->flags &= ~(SQT | DQT); 
}
