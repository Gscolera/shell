#include "shell.h"

void	shell_get_promt(t_settings *settings)
{
	struct passwd	*uid;

	uid = getpwuid(settings->uid);
	ft_strcpy(settings->promt, "{green}{bold}");
	ft_strcat(settings->promt, uid->pw_name);
	ft_strcat(settings->promt, "$>{eoc}");
}
