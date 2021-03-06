/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:18:13 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 15:31:07 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		shell_set_variable(t_shell *sh, char *var, char *value)
{
	char	*new_env;
	int		i;

	if (!(new_env = ft_strnew(ft_strlen(var) + ft_strlen(value) + 1)))
		shell_close(sh, ft_perror("sh", "malloc error"));
	ft_strcat(new_env, var);
	ft_strcat(new_env, "=");
	ft_strcat(new_env, value);
	i = -1;
	while (sh->env[++i])
	{
		if (ft_strnequ(sh->env[i], new_env, ft_strlen(var) + 1))
		{
			ft_strdel(&sh->env[i]);
			sh->env[i] = new_env;
			return ;
		}
	}
	string_add(&sh->env, new_env);
	ft_strdel(&new_env);
}

void		shell_delete_env(t_shell *sh, char *var)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(var);
	if (!string_search(sh->env, var))
		return ;
	while (sh->env[++i])
	{
		if (ft_strnequ(sh->env[i], var, len))
		{
			ft_strdel(&sh->env[i]);
			break ;
		}
	}
	while (sh->env[i + 1])
	{
		sh->env[i] = sh->env[i + 1];
		i++;
	}
	sh->env[i] = NULL;
}

void		shell_setenv(t_shell *sh, char **argv)
{
	if (count_strings(argv) != 3)
	{
		ft_perror("env", "wrong amount of arguments");
	}
	else if (ft_strlen(argv[1]) > VAR_NAME_MAX)
	{
		ft_perror("shell", "env name is too long");
	}
	else
	{
		shell_set_variable(sh, argv[1], argv[2]);
	}
}

void		shell_unsetenv(t_shell *sh, char **argv)
{
	char	buff[VAR_NAME_MAX + 2];
	int		i;

	i = 0;
	ft_memset(buff, 0, VAR_NAME_MAX + 2);
	while (argv[++i])
	{
		ft_strcat(buff, argv[i]);
		ft_strcat(buff, "=");
		shell_delete_env(sh, buff);
		ft_strclr(buff);
	}
}
