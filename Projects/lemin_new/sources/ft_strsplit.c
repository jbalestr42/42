/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 20:13:42 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/02 17:19:49 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		is_white_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

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

static size_t	ft_words(char const *s)
{
	int			i;
	size_t		size;

	i = 0;
	size = 0;
	while (s[i] && is_white_space(s[i]))
		i++;
	while (s[i])
	{
		while (s[i] && is_white_space(s[i]))
			i++;
		if (s[i])
		{
			while (s[i] && !is_white_space(s[i]))
				i++;
			size++;
		}
	}
	return (size);
}

char			**ft_splitwhite(char const *s)
{
	char		**tab;
	size_t		size;
	int			i;
	int			start;

	tab = NULL;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_words(s) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (is_white_space(s[i]))
			i++;
		else
		{
			start = i;
			while (s[i] && !is_white_space(s[i]))
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
	}
	tab[size] = 0;
	return (tab);
}
