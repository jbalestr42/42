/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 16:44:39 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/15 17:10:07 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdlib.h>

static char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*r;
	unsigned int	i;

	i = 0;
	if (!s || !(r = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

static int		ft_isdigit(int c)
{
	if (c >= (unsigned char)'0' && c <= (unsigned char)'9')
		return (1);
	return (0);
}

static char		**ft_split(char const *s, int nb_elem)
{
	char			**tab;
	unsigned int	size;
	unsigned int	start;
	int				i;

	if (!s || !(tab = (char **)malloc(sizeof(char *) * (nb_elem + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			start = i;
			while (s[i] && ft_isdigit(s[i]))
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
		else
			i++;
	}
	tab[size] = '\0';
	return (tab);
}

int				ft_atoi(const char *str)
{
	int		total;
	int		is_neg;

	total = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if ((is_neg = *str == '-' ? -1 : 1) == -1 || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		total = (total * 10) + (*str++ - '0');
	return (total * is_neg);
}

int				*ft_intsplit(char const *s, int nb_elem)
{
	int			*map;
	char		**tab;
	int			i;

	i = -1;
	tab = ft_split(s, nb_elem);
	if (!(map = (int *)malloc(sizeof(int) * nb_elem)))
		return (NULL);
	while (++i < nb_elem)
		map[i] = ft_atoi(tab[i]);
	if (map)
	{
		i = -1;
		while (++i < nb_elem)
			free(tab[i]);
		free(tab);
	}
	return (map);
}
