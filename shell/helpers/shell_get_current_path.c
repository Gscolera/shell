/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_current_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:53:41 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:43 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*shell_get_current_path(void)
{
	char path[LINE_MAX];

	ft_memset(path, 0, LINE_MAX);
	getcwd(path, LINE_MAX);
	return (ft_strdup(path));
}
