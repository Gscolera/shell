/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_switch_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:25:55 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/08 20:29:57 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_switch_flag(t_shell *sh, int flag)
{
	if (sh->flags & flag)
		sh->flags &= ~flag;
	else
		sh->flags |= flag;
}
