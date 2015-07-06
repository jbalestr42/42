/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:21:26 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 18:13:21 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "parser.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(s) * len);
	if (tmp)
	{
		while (len--)
		{
			tmp[i] = s[start];
			start++;
			i++;
		}
		tmp[i] = 0;
		return (tmp);
	}
	return (NULL);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int		u;

	u = 0;
	while (s1[u] || s2[u])
	{
		if (s1[u] != s2[u])
			return (s1[u] - s2[u]);
		u++;
	}
	return (0);
}

int			check_col(char *str)
{
	int		i;

	i = cut_space(str);
	while (str[i])
	{
		if (str[i] == ';')
			break ;
		i++;
	}
	if ((i - cut_space(str)) != 8)
		return (-1);
	return (0);
}

void		error_p(char *s1, char *s2, int l)
{
	write(1, "l", 1);
	ft_putnbr(l);
	write(1, ": ", 2);
	write(1, s2, ft_strlen(s2));
	write(1, ": \"", 3);
	write(1, s1, ft_strlen(s1));
	write(1, "\"\n", 2);
	free(s1);
}

int			free_ret(int ret, char **tmp)
{
	int		i;

	i = -1;
	while (tmp[++i] != NULL)
		free(tmp[i]);
	free(tmp);
	tmp = NULL;
	return (ret);
}
