#include "shell.h"

void	shell_get_promt(t_settings *settings)
{
	struct passwd	*uid;
	char			host[HOST_NAME];

	uid = getpwuid(settings->uid);
	ft_strcpy(settings->promt, "{green}{bold}");
	gethostname(host, HOST_NAME_MAX);
	ft_strcat(settings->promt, uid->pw_name);
	ft_strcat(settings->promt, "@");
	ft_strcat(settings->promt, host);
	ft_strcat(settings->promt, "\\$>{eoc} ");
}
