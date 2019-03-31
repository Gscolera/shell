/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:42:39 by gscolera          #+#    #+#             */
/*   Updated: 2019/03/10 22:12:27 by anton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_value(FORMAT *f, SINTMAX *binary)
{
	va_list			copy;

	if (f->flags & DOLLAR)
	{
		va_copy(copy, f->list);
		while (--f->argnum > 0)
			va_arg(copy, void*);
	}
	*binary = va_arg((f->flags & DOLLAR) ? copy : f->list, SINTMAX);
}

static void	print_bits(FORMAT *f, SINTMAX binary)
{
	SINTMAX	bit;

	bit = 1;
	add_char(f, 98);
	if (binary < 0)
		binary = binary * -1 + 1;
	while (bit < binary)
		bit *= 2;
	if (bit > binary)
		bit /= 2;
	while (bit != 0)
	{
		if (binary / bit > 0)
		{
			add_char(f, binary / bit + 48);
			binary %= bit;
			bit /= 2;
		}
		else
		{
			add_char(f, 48);
			bit /= 2;
		}
	}
}

void		manage_bits(FORMAT *f)
{
	SINTMAX binary;

	get_value(f, &binary);
	print_bits(f, binary);
}
