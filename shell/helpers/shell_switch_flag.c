/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_switch_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:25:55 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 19:04:10 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_switch_flag(int flag)
{
	if (g_flags & flag)
	{
		g_flags &= ~flag;
	}
	else
	{
		g_flags |= flag;
	}
}
