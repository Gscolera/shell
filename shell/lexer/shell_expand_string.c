#include "shell.h"

static bool	shell_in_single_quote(char *string, int i)
{
	register int	j;
	size_t			quotes;

	j = -1;
	quotes = 0;
	while (++j < i)
	{
		if (string[j] == '\'' && (j == 0 || string[j - 1] != '\\'))
			quotes++;
	}
	return ((quotes % 2 == 0) ? 0 : 1);

}

static void	shell_expand_home(char **env, char *string, char i)
{
	char *home;
	
	if (shell_in_single_quote(string, i))
		return ;
	home = shell_get_value(env, "HOME");
	if (ft_strlen(home) + ft_strlen(string) - 1 < LINE_MAX)
		ft_replace_substr(string, i, 1, home);
}

static void	shell_expand_variable(char **env, char *str, int i)
{
	char 			buff[LINE_MAX];
	char			*var;
 	int				size;

	size = 0;
	ft_bzero(buff, LINE_MAX);
	if (shell_in_single_quote(str, i))
		return ;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
	{
		size++;
		i++;
	}
	ft_strncpy(buff, &str[i - size], size);
	var = shell_get_value(env, &buff[1]);
	if (ft_strlen(str) - ft_strlen(buff) + ft_strlen(var) < LINE_MAX)
		ft_replace_substr(str, i - size, size, var);
}

void		shell_expand_string(t_shell *sh, char *string)
{
	register int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == '~' && (i == 0 || string[i - 1] != '\\'))
			shell_expand_home(sh->env, string, i);
		else if (string[i] == '$' && (i == 0 || string[i - 1] != '\\'))
			shell_expand_variable(sh->env, string, i);
	}
}
