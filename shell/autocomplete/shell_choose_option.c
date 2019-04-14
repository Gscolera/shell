/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_choose_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:29:17 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/13 20:07:33 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_reprint_input(t_reader *rd)
{
	ft_printf(rd->promt);
	shell_get_cursor_position(&rd->home);
	ft_printf(rd->history->data);
	g_flags &= ~CHOOSING;
}

static void	shell_print_in_colums(t_shell *sh, t_cmplt *list)
{
	size_t	row_capacity;
	size_t	left_in_row;

	row_capacity = (g_window_size.x - 10) / sh->options.max_len;
	while (list)
	{
		left_in_row = row_capacity;
		while (list && left_in_row--)
		{
			if (sh->act_list == list)
				ft_printf("{red}%-*s{eoc}", sh->options.max_len, list->option);
			else
				ft_printf("%-*s", sh->options.max_len, list->option);
			list = list->next;
		}
		shell_mvcd(sh, &sh->rd);
	}
}

static void	shell_print_options(t_shell *sh, t_cmplt *list)
{
	TERM_ACTION(CD);
	shell_mvcd(sh, &sh->rd);
	if (!sh->act_list || !sh->act_list->next)
		sh->act_list = sh->cmp_list;
	else
		sh->act_list = sh->act_list->next;
	if (sh->options.len >= g_window_size.x - 10)
		shell_print_in_colums(sh, list);
	else
	{
		while (list)
		{
			if (sh->act_list == list)
				ft_printf("{red}%s  {eoc}", list->option);
			else
				ft_printf("%s ", list->option);
			list = list->next;
		}
	}
	if (sh->rd.home.y > g_window_size.y)
		shell_reprint_input(&sh->rd);
	shell_get_cursor_position(&sh->rd.crs);
	shell_mvch(sh, &sh->rd);
	shell_mvce(sh, &sh->rd);
}

void		shell_choose_option(t_shell *sh, t_cmplt *list)
{
	char	buff[10];

	ft_memset(buff, 0, 10);
	shell_print_options(sh, list);
	while (g_flags & CHOOSING)
	{
		read(fileno(stdin), buff, 10);
		if (buff[0] == KEYTAB)
			shell_print_options(sh, list);
		else if (buff[0] == KEYENTER)
		{
			shell_accept_option(sh, sh->act_list);
			g_flags &= ~CHOOSING;
		}
		else if (buff[0] == KEYESC)
			g_flags &= ~CHOOSING;
		else if (ft_isprint(buff[0]) || buff[0] == 127)
		{
			(ft_isprint(buff[0])) ? shell_insert_char(sh, &sh->rd, buff[0]) : 0;
			(buff[0] == 127) ? shell_delete_char(sh, &sh->rd, KEYBS) : 0;
			g_flags &= ~CHOOSING;
		}
		ft_strclr(buff);
	}
}
