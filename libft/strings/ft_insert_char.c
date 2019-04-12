/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:46:30 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:46:38 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insert_char(char *string, char c, size_t pos)
{
	size_t	i;

	if (!string || (i = ft_strlen(string)) < pos)
		return ;
	while (i > pos)
	{
		string[i] = string[i - 1];
		i--;
	}
	string[i] = c;
}
