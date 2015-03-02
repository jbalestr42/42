/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 18:35:15 by hjeannin          #+#    #+#             */
/*   Updated: 2014/05/15 00:29:43 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

static size_t		ft_wordcount(char const *s, char *c)
{
	size_t		wcount;
	size_t		i;

	i = 0;
	wcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c[0] || s[i] == c[1])
			i++;
		while ((s[i] != c[0] && s[i] != c[1]) && s[i] != '\0')
		{
			if ((s[i + 1] == c[0] || s[i + 1] == c[1]) || s[i + 1] == '\0')
				wcount++;
			i++;
		}
	}
	return (wcount);
}

static char			**ft_addwords(char **tab, char const *s, size_t i, char *c)
{
	size_t		wstart;
	size_t		t;

	t = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c[0] || s[i] == c[1])
			i++;
		wstart = i;
		while ((s[i] != c[0] && s[i] != c[1]) && s[i] != '\0')
		{
			if ((s[i + 1] == c[0] || s[i + 1] == c[1]) || s[i + 1] == '\0')
			{
				tab[t] = ft_strsub(s, wstart, i + 1 - wstart);
				t++;
			}
			i++;
		}
	}
	return (tab);
}

char				**ft_strsplit2(char const *s, char c, char c2)
{
	char		**tab;
	size_t		i;
	char		tc[2];

	tc[0] = c;
	tc[1] = c2;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * ft_wordcount(s, tc) + 1)))
	{
		perror("ft_strsplit2()");
		return (NULL);
	}
	tab = ft_addwords(tab, s, i, tc);
	tab[ft_wordcount(s, tc)] = '\0';
	return (tab);
}
