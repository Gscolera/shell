/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_manage_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:28 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/13 18:43:32 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		shell_manage_input(t_shell *sh)
{
	if (sh->input)
	{
		sh->input = shell_expand_string(sh, sh->input);
		shell_split_input(sh, sh->input);
		shell_split_commands(sh, sh->cmd_list);
		ft_strdel(&sh->input);
	}
}
