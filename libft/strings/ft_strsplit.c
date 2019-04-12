/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anton <anton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:37:43 by gscolera          #+#    #+#             */
/*   Updated: 2019/04/12 14:52:19 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		split_size(char const *s, char c)
{
	int		size;
	int		i;

	i = 0;
	if (!s)
		return (0);
	size = 1;
	while (s[++i])
	{
		if (s[i] == c && i > 0 && s[i + 1])
			size++;
		while (s[i + 1] && s[i] == c)
			i++;
	}
	return (size);
}

static char		*get_next_word(char **splt, char *str, int i, char c)
{
	int j;

	j = 0;
	while (str[j] && str[j] != c)
		j++;
	splt[i] = ft_strsub(str, 0, j);
	while (str[j] == c)
		j++;
	str += j;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**splt;
	char	*str;
	int		size;
	int		i;

	str = (char *)s;
	if (!(size = split_size(s, c)))
		return (NULL);
	if (!(splt = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
		str = get_next_word(splt, str, i, c);
	splt[i] = NULL;
	return (splt);
}
