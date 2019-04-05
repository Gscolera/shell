/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:55:22 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/04 22:09:32 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_execute(t_shell *sh)
{
	ft_putchar('\n');
	if (sh->cmd)
	{
		print_strings(sh->cmd);
		free_strings(sh->cmd);
		sh->cmd = NULL;
	}
	ft_strdel(&sh->input);
}
