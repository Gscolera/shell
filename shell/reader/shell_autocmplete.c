/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_autocmplete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:01:18 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/01 22:00:48 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		shell_autocmplt_add_to_list(t_shell *sh, t_reader *rd, char *name)
{
	t_bufflist *new;

	new = (t_bufflist *)ft_memalloc(sizeof(t_bufflist));
	if (!new)
		exit(sh, ft_perror("shell", "memory allocation error"));
	new->next = NULL;
}

static void		shell_look_for_binary(t_shell *sh, t_reader *rd, char *line)
{
	DIR				*dir_ptr;
	struct dirent	*sd;
	register int 	i;

	i = -1;
	while (sh->paths[++i])
	{
		dir_ptr = opendir(sh->path[i]);
		if (!dir_ptr)
			continue ;
		while (sd = readdir(dir_ptr))
		{
			if (ft_strnequ(sd->d_name, line, rd->ic && ft_strlen(sd->d_name) > rd->ic))  
				shell_autcmplt_add_to_list(sh, rd, sd->d_name);
		}
	}
}

static void		shell_create_autocomplete_list(t_shell *sh, t_reader *rd)
{
	char	line[LINE_MAX];

	ft_bzero(line, LINE_MAX);
	ft_strncpy(line, rd->history->data, rd->ic + 1);
	if (!ft_strchr(line, ' '))
		(rd->history->data[0] == '.') ? NULL : shell_look_for_binary(sh, rd, line);
}

void			shell_autocomplete(t_shell *sh, t_reader *rd)
{
	if (!rd->aucmplt)
		shell_create_autocomplete_list(sh, rd);
	else if (rd->aucmplt->next)
		rd->aucmplt_ptr = rd->aucmplt->next;


}
