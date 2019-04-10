#include "shell.h"

void		shell_cmplt_end(t_shell *sh)
{
	t_cmplt	*tmp;

	while (sh->cmp_list)
	{
		tmp = sh->cmp_list->next;
		ft_strdel(&sh->cmp_list->option);
		free(sh->cmp_list);
		sh->cmp_list = tmp;
	}
	sh->cmp_list = NULL;
	free_strings(sh->path);
	sh->flags &= ~ CHOOSING;
	TERM_ACTION(CD);
}

void		shell_complete_input(t_shell *sh, t_cmplt *list)
{
	int	i;

	i = ft_strlen(sh->input);
	while (list->option[i])
		shell_insert_char(sh, &sh->rd, list->option[i++]);
}

void		shell_autocomplete(t_shell *sh)
{
	shell_mvce(sh, &sh->rd);
	ft_strclr(sh->cmp);
	ft_strcpy(sh->cmp, sh->history->data);
	(sh->cmp_list) ? shell_check_options(sh, sh->cmp_list) : NULL;
	if (!sh->cmp_list && !ft_strchr(sh->cmp, ' '))
		shell_search_for_arguments()
	
	TERM_ACTION(SAVEC);
	TERM_ACTION(DOWN);
	ft_printf("COMPLETING");
	TERM_ACTION(RSRC);
	sh->flags |= CHOOSING;
		
	
}
