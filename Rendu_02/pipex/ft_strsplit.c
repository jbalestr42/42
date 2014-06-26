/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:03:05 by jbalestr          #+#    #+#             */
/*   Updated: 2014/05/09 18:03:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		lin;
	int		col;
	char	**new;

	i = 0;
	lin = ft_clines(s, c);
	col = ft_ccol(s, c);
	if ((new = (char**)malloc(sizeof(char*) * lin + 1)) == NULL)
		return (NULL);
	new[lin + 1] = 0;
	while (i <= lin)
	{
		if ((new[i] = (char*)malloc(sizeof(char) * col + 1)) == NULL)
			return (NULL);
		i++;
	}
	if (s == 0)
	{
		new[lin][0] = 0;
		return (new);
	}
	else
		return (ft_strsplit_fill(s, c, new));
}

char	**ft_strsplit_fill(char const *s, char c, char **new)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			new[j][k] = s[i];
			i++;
			k++;
		}
		new[j][k] = '\0';
		if (s[i - 1] != c)
			j++;
	}
	new[j] = '\0';
	return (new);
}

int		ft_ccol(char const *s, char c)
{
	int		i;
	int		length;
	int		len_tmp;

	i = 0;
	length = 1;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if ((s[i] != c && s[i - 1] == c) || (s[0] != c))
		{
			len_tmp = 0;
			while (s[i] != c && s[i])
			{
				len_tmp++;
				i++;
			}
			if (len_tmp > length)
				length = len_tmp;
		}
	}
	return (length);
}

int		ft_clines(char const *s, char c)
{
	int		i;
	int		words;

	words = 1;
	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == c)
			words++;
	}
	return (words);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] != s2[i] && i < n)
		return (s1[i] - s2[i]);
	return (0);
}
