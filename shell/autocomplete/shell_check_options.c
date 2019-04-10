/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_check_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:44:43 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/10 21:49:45 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_check_options(t_shell *sh, t_cmplt *list)
{
	t_cmplt		*prev;
	int			len;

	prev = NULL;
	len = ft_strlen(sh->cmp);
	while (list)
	{
		if (!ft_strnequ(sh->cmp, list->option, len))
		{
			if (prev)
				prev->next = list->next;
			else
				sh->cmp_list = list->next;
			ft_memdel((void**)&list);
		}
		prev = (list) ? list : prev;
		if (!list)
			list = (prev) ? prev->next : sh->cmp_list;
		else
			list = list->next;
	}
}
