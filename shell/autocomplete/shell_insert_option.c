/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_insert_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:54:29 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:52:55 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_insert_option(t_shell *sh, t_cmplt *new_list)
{
	t_cmplt	*tmp;

	tmp = sh->cmp_list;
	if (ft_strcmp(tmp->option, new_list->option) > 0)
	{
		new_list->next = tmp;
		sh->cmp_list = new_list;
		return ;
	}
	while (tmp->next)
	{
		if (ft_strcmp(tmp->next->option, new_list->option) > 0)
		{
			new_list->next = tmp->next;
			tmp->next = new_list;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = new_list;
}
