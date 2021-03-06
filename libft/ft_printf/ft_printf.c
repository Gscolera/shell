/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:14:49 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/14 21:29:14 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool		init_format(FORMAT *f)
{
	ft_memset(f->output, 0, LINE_MAX);
	f->argnum = 0;
	f->flags = 0;
	f->prec = 0;
	f->width = 0;
	f->length = 0;
	return (1);
}

static void		clean_format(FORMAT *f)
{
	f->argnum = 0;
	f->flags = 0;
	f->prec = 0;
	f->width = 0;
}

static bool		manage_text_format(FORMAT *f)
{
	if (compare(f, "{red}"))
		add_string(f, "\033[31m");
	else if (compare(f, "{green}"))
		add_string(f, "\033[32m");
	else if (compare(f, "{yellow}"))
		add_string(f, "\033[33m");
	else if (compare(f, "{blue}"))
		add_string(f, "\033[34m");
	else if (compare(f, "{magenta}"))
		add_string(f, "\033[35m");
	else if (compare(f, "{cyan}"))
		add_string(f, "\033[36m");
	else if (compare(f, "{bold}"))
		add_string(f, "\033[1m");
	else if (compare(f, "{italic}"))
		add_string(f, "\033[3m");
	else if (compare(f, "{underline}"))
		add_string(f, "\033[4m");
	else if (compare(f, "{eoc}"))
		add_string(f, "\033[0m");
	else
		return (0);
	return (1);
}

static void		manage_output(FORMAT *f)
{
	while (CHAR)
	{
		if (CHAR == '{')
		{
			if (!manage_text_format(f))
				add_char(f, CHAR);
		}
		else if (CHAR == '%')
		{
			manage_conversion(f);
			clean_format(f);
		}
		else
			add_char(f, CHAR);
		NEXT;
	}
}

int				ft_printf(const char *format, ...)
{
	FORMAT f;

	if (format[0] == '%' && !format[1])
		return (0);
	if (!(init_format(&f)))
		return (-1);
	f.pos = (char*)format;
	va_start(f.list, format);
	manage_output(&f);
	va_end(f.list);
	if (f.length)
	{
		write(fileno(stdout), f.output, f.length);
		return (f.length);
	}
	return (-1);
}
