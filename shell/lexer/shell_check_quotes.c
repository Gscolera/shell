/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_check_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:57:47 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 19:21:51 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

bool	shell_check_quotes(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (QUOTE(input[i]))
			shell_manage_quote(input, i);
	}
	return ((NQT(g_flags)) ? 1 : 0);
}
