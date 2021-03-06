/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:42:01 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:42:03 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wchar_len(wchar_t c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	else
		return (4);
}

int		ft_wstr_len(wchar_t *wstr)
{
	int count;

	count = 0;
	while (*wstr)
	{
		count += ft_wchar_len(*wstr);
		wstr++;
	}
	return (count);
}
