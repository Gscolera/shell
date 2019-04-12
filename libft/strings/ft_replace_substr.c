/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_substr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:46:51 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:49:01 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_substr(char *str, size_t pos, size_t len, char *new)
{
	if (!str || !new || pos + len > ft_strlen(str))
		return ;
	while (len--)
		ft_delete_char(str, pos);
	while (*new)
		ft_insert_char(str, *(new++), pos++);
}
