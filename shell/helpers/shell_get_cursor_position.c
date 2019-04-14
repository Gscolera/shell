/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_cursor_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:10:52 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/13 19:11:30 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_get_cursor_position(t_coordinate *crs)
{
	char buf[15];
	int ret;
	int i;
	
	i = -1;
	ft_memset(crs, 0, sizeof(t_coordinate));
	write(1, "\033[6n", 4);
	ret = read(0, buf, 15);
	while (++i < ret && buf[i] != ';')
	{
		if (ft_isdigit(buf[i]))
			crs->y = crs->y * 10 + buf[i] - 48;
	}
	while (i < ret)
	{
		if (ft_isdigit(buf[i]))
			crs->x = crs->x * 10 + buf[i] - 48;
		i++;
	}
	crs->x -= 1;
}
