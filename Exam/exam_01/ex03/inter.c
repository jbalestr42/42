/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 14:55:21 by exam              #+#    #+#             */
/*   Updated: 2014/01/30 15:18:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		fill_tab(char *s1, char *tab, int *max)
{
	int		i;

	while (*s1)
	{
		i = -1;
		while (++i < *max)
		{
			if (tab[i] == *s1)
				break ;
		}
		if (i == *max)
			*max = *max + 1;
		tab[i] = *s1;
		s1++;
	}
}

void		inter(char *s1, char *s2)
{
	char	t[255];
	int		i;
	int		j;
	int		max;

	i = -1;
	max = 0;
	while (++i < 255)
		t[i] = 0;
	fill_tab(s1, t, &max);
	i = -1;
	while (++i < max)
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == t[i])
			{
				write(1, &t[i], 1);
				break ;
			}
			j++;
		}
	}
}

int			main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
