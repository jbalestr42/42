/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 08:41:44 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/15 16:06:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static int				ft_isvalid(char c)
{
	if (ft_isdigit(c) || c == '+' || c == '-')
		return (1);
	return (0);
}

static unsigned int		ft_words(char const *s)
{
	int				i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && !ft_isvalid(s[i]))
			i++;
		if (s[i])
		{
			while (s[i] && ft_isvalid(s[i]))
				i++;
			size++;
		}
	}
	return (size);
}

static char				**ft_fdfsplit(char const *s, int *nb_elem)
{
	char			**tab;
	unsigned int	size;
	unsigned int	start;
	int				i;

	*nb_elem = ft_words(s);
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (*nb_elem + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (ft_isvalid(s[i]))
		{
			start = i;
			while (s[i] && ft_isvalid(s[i]))
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
		else
			i++;
	}
	tab[size] = '\0';
	return (tab);
}

t_point					**ft_intsplit(char const *s, int nb_line, int *nb_elem)
{
	t_point		**line;
	char		**tab;
	int			i;

	i = 0;
	tab = ft_fdfsplit(s, nb_elem);
	if (!(line = (t_point **)malloc(sizeof(t_point *) * *nb_elem)))
		return (NULL);
	while (i < *nb_elem)
	{
		if (!(line[i] = (t_point *)malloc(sizeof(t_point))))
			return (NULL);
		line[i]->x = i;
		line[i]->y = nb_line;
		line[i]->z = ft_atoi(tab[i]) * 2;
		i++;
	}
	return (line);
}
