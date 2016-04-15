/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:00:21 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 15:00:23 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen_tab(char **tab)
{
	int			len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void			free_split(char **s)
{
	int			i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

static size_t	ft_words(char const *s, char c)
{
	int			i;
	size_t		size;

	i = 0;
	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			size++;
		}
	}
	return (size);
}

static char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tmp;
	int			i;

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

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		size;
	int			i;
	int			start;

	tab = NULL;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
	}
	tab[size] = NULL;
	return (tab);
}
