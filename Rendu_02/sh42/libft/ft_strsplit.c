/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:40:39 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 21:18:18 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_wordcount(char const *s, char c)
{
	size_t		wcount;
	size_t		i;

	i = 0;
	wcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				wcount++;
			i++;
		}
	}
	return (wcount);
}

static char			**ft_addwords(char **tab, char const *s, size_t i, char c)
{
	size_t		wstart;
	size_t		t;

	t = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		wstart = i;
		while (s[i] != c && s[i] != '\0')
		{
			if ((s[i + 1] == c || s[i + 1] == '\0'))
			{
				tab[t] = ft_strsub(s, wstart, i + 1 - wstart);
				t++;
			}
			i++;
		}
	}
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * ft_wordcount(s, c) + 1)))
		return (NULL);
	tab = ft_addwords(tab, s, i, c);
	tab[ft_wordcount(s, c)] = '\0';
	return (tab);
}
