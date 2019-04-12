/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_delete_characters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:53:33 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:53:36 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_delete_characters(char *string, char *dlt)
{
	int	i;
	int	j;

	i = -1;
	while (string[++i])
	{
		j = -1;
		while (dlt[++j])
		{
			while (string[i] == dlt[j])
				ft_delete_char(string, i);
		}
	}
}
