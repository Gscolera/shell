/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:52:20 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/03 21:14:43 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		shell_split_input(t_shell *sh)
{
	char	*input;
	char	*ptr;

	input = ft_strdup(sh->rd.history->data);
	ptr = input;
	while (*input)
	{
		if (shell_quote(ptr, input) && NQUOTE(sh->flags))
		{
			sh->flags |= QUOTE;
			ft_printf("\nQT");
		}
		input++;
	}
	sh->flags
}
