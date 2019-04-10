/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_change_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:16:44 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/10 15:48:20 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	shell_print_chdir_error(char *dir)
{
	struct stat st;

	if (lstat(dir, &st) == -1)
		ft_perror(dir, "no such file or directory");
	else if (!S_ISDIR(st.st_mode))
		ft_perror(dir, "not a directory");
	else if (access(dir, FILE_EXEC))
		ft_perror(dir, "permission denied");
	return (1);
}

static void	shell_set_pwd(t_shell *sh, char *dir)
{
	char	pwd[LINE_MAX];

	getcwd(pwd, LINE_MAX);
	shell_set_variable(sh, "OLDPWD", shell_getenv(sh->env, "PWD", 3));
	shell_set_variable(sh, "PWD", pwd);
}

int		shell_change_dir(t_shell *sh, char **av)
{
	char	*dir;

	if (count_strings(av) != 2)
		return (ft_perror("cd", "wrong amount of arguments"));
	dir = (ft_strequ(av[1], "-")) ? shell_getenv(sh->env, "OLDPWD", 6) : av[1];
	if (!dir)
		return (ft_perror("cd", "OLDPWD not set"));	
	if (chdir(dir) == -1)
		return (shell_print_chdir_error(dir));
	shell_set_pwd(sh, av[1]);
	return (0);
}
