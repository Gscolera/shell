/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:55:51 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 15:04:43 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*shell_copy_command(char *input, int i)
{
	input[i--] = '\0';
	while (i > 0 && (input[i] == ' ' || input[i] == '\t'))
		ft_delete_char(input, i--);
	if (i < 0)
		return (NULL);
	while (*input == ' ' || *input == '\t')
	{
		ft_delete_char(input, 0);
		i--;
	}
	return ((input[0]) ? ft_strdup(input) : NULL);
}

static void	shell_get_next_command(t_shell *sh, char *input, int i)
{
	t_command	*new_cmd;
	t_command	*tmp;

	if (!(new_cmd = (t_command *)ft_memalloc(sizeof(t_bufflist))))
		shell_close(sh, ft_perror("shell", "malloc error"));
	if (!(new_cmd->cmd = shell_copy_command(input, i)))
		ft_memdel((void **)new_cmd);
	else
	{
		new_cmd->next = NULL;
		new_cmd->argv = NULL;
	}
	if (!sh->cmd_list && new_cmd)
		sh->cmd_list = new_cmd;
	else if (new_cmd)
	{
		tmp = sh->cmd_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cmd;
	}
}

void		shell_split_input(t_shell *sh, char *input)
{
	int i;

	i = -1;
	while (input[++i])
	{
		if (QUOTE(input[i]))
			shell_manage_quote(input, i);
		else if (QUOTE(input[i]) && i == 0)
			ft_delete_char(input, i--);
		else if (input[i] == ';' && NQT(g_flags))
		{
			if (i == 0)
				ft_delete_char(input, i);
			else
			{
				shell_get_next_command(sh, input, i);
				input = &input[i + 1];
			}
			i = -1;
		}
	}
	if (i > 0 && NQT(g_flags))
		shell_get_next_command(sh, input, i);
	g_flags &= ~(DQT | SQT);
}
