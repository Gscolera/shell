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
		shell_parse_input(&sh, &sh.rd);
		//shell_execute(&sh);
	}
	return (EXIT_SUCCESS);
}
