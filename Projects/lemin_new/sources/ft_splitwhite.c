/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 22:39:36 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/02 17:20:01 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	tab[size] = 0;
	return (tab);
}
