/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_read_config_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:06 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 15:29:00 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	shell_read_config_line(t_settings *settings, char *buffer)
{
	if (ft_strnequ(buffer, "PROMT=", 6))
		ft_strncpy(settings->promt, buffer + 6, PROMT_MAX);
	else if (ft_strnequ(buffer, "HISTORYSIZE=", 12))
		settings->history_buffsize = ft_atoi(buffer + 12);
}

void		shell_read_config_file(t_shell *sh)
{
	int		fd;
	char	*buffer;

	if ((fd = open(CONFIG_FILE, O_RDONLY)) == -1)
		return ;
	while (get_next_line(fd, &buffer))
	{
		if (buffer[0] != '#')
			shell_read_config_line(&sh->settings, buffer);
		ft_strdel(&buffer);
	}
	close(fd);
}
