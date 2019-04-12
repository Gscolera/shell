/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_change_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:16:44 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 15:33:14 by gscolera         ###   ########.fr       */
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

static void	shell_set_pwd(t_shell *sh)
{
	char	pwd[LINE_MAX];

	getcwd(pwd, LINE_MAX);
	shell_set_variable(sh, "OLDPWD", shell_getenv(sh->env, "PWD", 3));
	shell_set_variable(sh, "PWD", pwd);
}

int			shell_change_dir(t_shell *sh, char **av)
{
	char		*dir;
	size_t		count;

	count = count_strings(av);
	if (count > 2)
		return (ft_perror("cd", "wrong amount of arguments"));
	else if (count == 1)
	{
		if (!(dir = shell_getenv(sh->env, "HOME", 4)))
			return (ft_perror("cd", "variable home not set"));
	}
	else if (ft_strequ(av[1], "-"))
	{
		if (!(dir = shell_getenv(sh->env, "OLDPWD", 6)))
			return (ft_perror("cd", "OLDPWD not set"));
	}
	else
		dir = av[1];
	if (chdir(dir) == -1)
		return (shell_print_chdir_error(dir));
	shell_set_pwd(sh);
	return (0);
}
