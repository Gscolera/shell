/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_promt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:53:48 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:49 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_get_promt(t_settings *settings)
{
	struct passwd	*uid;
	char			host[HOST_NAME];

	uid = getpwuid(settings->uid);
	ft_strcpy(settings->promt, "{green}{bold}");
	gethostname(host, HOST_NAME);
	ft_strcat(settings->promt, uid->pw_name);
	ft_strcat(settings->promt, "@");
	ft_strcat(settings->promt, host);
	ft_strcat(settings->promt, "\\$>{eoc} ");
}
