/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:46:21 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:46:29 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_char(char *string, size_t pos)
{
	if (!string || pos >= ft_strlen(string))
		return ;
	while (string[pos])
	{
		string[pos] = string[pos + 1];
		pos++;
	}
}
