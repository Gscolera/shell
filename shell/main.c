#include "shell.h"

/*
 ******* This is a 42 school(Moscow campus) Unix-branch project*******
 ******* The aim of it is to recode a command line interpreter********
 ******* For this project it is prohibited to use:********************
 ******* * most of standart library functions*************************
 ******* * errno (I need to manage errors by my own)******************
 ******* Using of global variables is allowed in certian cases********
 */

int		main(void)
{
	t_shell sh;

	shell_open(&sh);
	ft_putstr("\033]2;MINIFUCKINGSHELL\007");
	tputs(sh.rd.esc[CLR], fileno(stdin), ft_putchar);
	while (true)
	{
		shell_read_input(&sh, &sh.rd);
		shell_parse_input(&sh, &sh.rd);
		//shell_execute(&sh);
	}
	return (EXIT_SUCCESS);
}
