#include "shell.h"

void	shell_print_promt(t_shell *sh)
{
	ft_strclr(sh->rd.buffer);
	ft_strcpy(sh->rd.buffer, sh->settings.promt);
	shell_expand_string(sh, sh->rd.buffer);
	shell_delete_chars_from_string(sh->rd.buffer, "\'\"\\");
	shell_count_promt_len(&sh->settings, sh->rd.buffer);
	sh->rd.buffer[ft_strlen(sh->rd.buffer)] = ' ';
	ft_printf(sh->rd.buffer);
	sh->rd.il = 0;
	sh->rd.ic = 0;
	sh->rd.crs.y = 0;
	sh->rd.crs.x = ++sh->settings.promt_len;
	sh->flags |= READING;
}
