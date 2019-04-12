/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:55:00 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:55:01 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(void)
{
	t_shell sh;

	shell_open(&sh);
	ft_putstr("\033]2;MINIFUCKINGSHELL\007");
	tputs(sh.rd.esc[CLR], fileno(stdin), ft_putchar);
	while (true)
	{
		shell_read_input(&sh, &sh.rd);
		shell_manage_input(&sh);
		shell_execute(&sh);
	}
	return (EXIT_SUCCESS);
}
