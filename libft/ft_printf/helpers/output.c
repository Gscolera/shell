/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:56:23 by gscolera          #+#    #+#             */
/*   Updated: 2019/01/13 15:57:19 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			add_char(FORMAT *f, char c)
{
	f->output[f->length++] = c;
}

void			add_string(FORMAT *f, char *str)
{
	while (*str)
	{
		add_char(f, *str);
		str++;
	}
}

void			add_wchar(FORMAT *f, wchar_t c)
{
	if (c < 0x80)
		add_char(f, c);
	else if (c < 0x800)
	{
		add_char(f, WCHAR21);
		add_char(f, WCHAR22);
	}
	else if (c < 0x10000)
	{
		add_char(f, WCHAR31);
		add_char(f, WCHAR32);
		add_char(f, WCHAR33);
	}
	else if (c < 0x110000)
	{
		add_char(f, WCHAR41);
		add_char(f, WCHAR42);
		add_char(f, WCHAR43);
		add_char(f, WCHAR44);
	}
}

void			add_sign(FORMAT *f)
{
	if (f->flags & MINUS)
		add_char(f, 45);
	else if (f->flags & PLUS)
		add_char(f, 43);
	else
		add_char(f, 32);
}
