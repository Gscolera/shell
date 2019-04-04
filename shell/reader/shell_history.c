#include "shell.h"

static void	shell_free_last_bufflist(t_reader *rd)
{
	t_bufflist	*tmp;

	tmp = rd->buffend;
	rd->buffend = rd->buffend->prev;
	rd->buffend->next = NULL;
	ft_memdel((void **)&tmp);
}

void	shell_create_history_list(t_shell *sh, t_reader *rd)
{
	rd->buffptr = (t_bufflist *)ft_memalloc(sizeof(t_bufflist));
	if (!rd->buffptr)
		shell_close(sh, ft_perror("shell", "memory allocation error"));
	if (!(rd->buffptr->data = (char *)ft_memalloc(BUFF_SIZE)))
		shell_close(sh, ft_perror("shell", "memory allocation error"));
	rd->buffptr->size = BUFF_SIZE;
	rd->buffptr->next = NULL;
	rd->buffptr->prev = NULL;
	if (!rd->history)
	{
		rd->buffptr->id = 0;
		rd->history = rd->buffptr;
		rd->buffend = rd->buffptr;
	}
	else
	{
		rd->buffptr->id = rd->history->id + 1;
		rd->buffptr->next = rd->history;
		rd->history->prev = rd->buffptr;
		rd->history = rd->buffptr;
		if (rd->history->id > sh->settings.history_buffsize)
			shell_free_last_bufflist(rd);
	}

}

void	shell_scroll_history(t_shell *sh, t_reader *rd, int keycode)
{
	register int	i;

	if (keycode == KEYUP && !rd->buffptr->next)
		return ;
	if (keycode == KEYDOWN && !rd->buffptr->prev)
		return ;
	i = -1;
	rd->il = 0;
	ft_strclr(rd->history->data);
	rd->buffptr = (keycode == KEYUP) ? rd->buffptr->next : rd->buffptr->prev;
	shell_mvch(sh, rd);
	TERM_ACTION(CD);
	while (rd->buffptr->data[++i])
		shell_insert_char(sh, rd, rd->buffptr->data[i]);
}
