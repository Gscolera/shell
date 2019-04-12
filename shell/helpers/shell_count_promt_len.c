/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_count_promt_len.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:53:27 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:28 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		shell_count_promt_len(t_settings *settings, char *promt)
{
	register int	i;
	register bool	stat;

	i = 0;
	settings->promt_len = 0;
	stat = true;
	while (promt[i])
	{
		if (promt[i] == '{')
			stat = false;
		else if (promt[i] == '}')
			stat = true;
		else if (stat == true)
			settings->promt_len++;
		i++;
	}
}
