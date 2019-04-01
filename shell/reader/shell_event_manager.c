#include "shell.h"

void	test(t_shell *sh, t_reader *rd)
{
	int fd = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	
	ft_putstr_fd("CRS X ", fd);
	ft_putnbr_fd(rd->crs.x, fd);
	ft_putstr_fd("\nCRS Y ", fd);
	ft_putnbr_fd(rd->crs.y, fd);
	ft_putstr_fd("\nIC ", fd);
	ft_putnbr_fd(rd->ic, fd);
	ft_putstr_fd("\nIL X ", fd);
	ft_putnbr_fd(rd->il, fd);
	ft_putstr_fd("\nPL ", fd);
	ft_putnbr_fd(sh->settings.promt_len, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}

static int	shell_get_keycode(char *key, int *keycode)
{
	if (!key[1])
	{
		*keycode = *key;
		return (1);
	}
	if (!key[2])
	{
		*keycode = ((key[0] << 8) | key[1]);
		return (2);
	}
	if (!key[3])
	{
		*keycode = ((key[0] << 16) | (key[1] << 8) | key[2]);
		return (3);
	}
	else
	{
		*keycode = ((key[0] << 24) | (key[1] << 16) | (key[2] << 8) | key[3]);
		return (4);
	}

}

int			shell_parse_events(t_shell *sh, t_reader *rd, char *key)
{
	int keycode;
	int key_len;

	key_len = shell_get_keycode(key, &keycode);
	if (keycode == KEYESC)
		shell_close(sh, EXIT_SUCCESS);
	else if (keycode == KEYLEFT && rd->ic > 0)
		shell_mvcl(sh, rd);
	else if (keycode == KEYRIGHT && rd->ic < rd->il)
		shell_mvcr(sh, rd);
	else if (keycode == KEYHOME)
		shell_mvch(sh, rd);
	else if (keycode == KEYEND)
		shell_mvce(sh, rd);
	else if (keycode == KEYENTER)
		sh->flags &= ~READING;
	else if (keycode == KEYUP || keycode == KEYDOWN)
		shell_scroll_history(sh, rd, keycode);
	else if (keycode == KEYTAB && rd->history->data[0])
		shell_autocomplete(sh, rd);
	else if (keycode == KEYDEL || keycode == KEYBS)
		shell_delete_char(sh, rd, keycode);
	else if (keycode == KEYHOME)
		test(sh, rd);
	return (key_len - 1);
}

