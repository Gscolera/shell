/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_delete_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:53:30 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:31 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_delete_char(t_shell *sh, t_reader *rd, int key)
{
	if ((key == KEYDEL || key == KEYCRTLD) && rd->ic == rd->il)
		return ;
	if (key == KEYBS && rd->ic == 0)
		return ;
	if (key == KEYBS)
		shell_mvcl(sh, rd);
	ft_delete_char(rd->history->data, rd->ic);
	rd->il--;
	TERM_ACTION(DEL);
	TERM_ACTION(SAVEC);
	TERM_ACTION(CD);
	ft_putstr(&rd->history->data[rd->ic]);
	TERM_ACTION(RSRC);
}
