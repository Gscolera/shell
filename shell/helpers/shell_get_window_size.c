#include "shell.h"

void	shell_get_window_size(t_coordinate *window_size)
{
	struct winsize w;

	ioctl(fileno(stdin), TIOCGWINSZ, &w);
	window_size->x = w.ws_col;
	window_size->y = w.ws_row;
}
