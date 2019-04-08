/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:55:22 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/08 19:32:41 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_execute(t_shell *sh)
{
	t_command *tmp;
	
	ft_putchar('\n');
	ft_strdel(&sh->input);
	while (sh->cmd_list)
	{
		tmp = sh->cmd_list->next;
		ft_strdel(&sh->cmd_list->cmd);
		ft_putendl("-----------------");
		print_strings(sh->cmd_list->argv);
		ft_putendl("-----------------");
		free_strings(sh->cmd_list->argv);
		free(sh->cmd_list);
		sh->cmd_list = tmp;
	}
	sh->cmd_list = NULL;
}
