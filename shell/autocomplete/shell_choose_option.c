/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_choose_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:29:17 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/10 20:31:20 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_print_options(t_shell *sh, t_cmplt *list)
{
	TERM_ACTION(SAVEC);
	TERM_ACTION(CD);
	TERM_ACTION(DOWN);
	while (list)
	{
		if (sh->act_list == list)
			ft_printf("{red}{bold}%s  {eoc}", list->option);
		else
			ft_printf("%s ", list->option);
		list = list->next;
	}
	TERM_ACTION(RSRC);
	sh->act_list = (sh->act_list->next) ? sh->act_list->next : sh->cmp_list;
}

static void	shell_parse_options(t_shell *sh, t_cmplt *list, char *buffer)
{
	int	i;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == KEYTAB)
			shell_print_options(sh, list);
		else if (buffer[i] == KEYENTER)
			sh->flags &= ~CHOOSING;
		else if (ft_isprint(buffer[i]))
		{
			shell_insert_char(sh, &sh->rd, buffer[i]);
			sh->flags &= ~CHOOSING;
		}
	}
	ft_strclr(buffer);
}

void		shell_choose_option(t_shell *sh, t_cmplt *list)
{
	char 	buff[LINE_MAX + 1];

	ft_memset(buff, 0, LINE_MAX + 1);
	sh->act_list = sh->cmp_list;
	shell_print_options(sh, list);
	sh->flags |= CHOOSING;
	while (sh->flags & CHOOSING)
	{
		read(fileno(stdin), buff, LINE_MAX);
		shell_parse_options(sh, list, buff);
	}
}
