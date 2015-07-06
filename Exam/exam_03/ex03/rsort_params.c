/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsort_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 15:34:19 by exam              #+#    #+#             */
/*   Updated: 2014/02/20 16:55:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			if (*s1 > *s2)
				return (-1);
			return (1);
		}
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

void		ft_putstr(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	write(1, "\n", 1);
}

void		rsort_param(int nb, char **tab)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < nb - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	i = -1;
	while (++i < nb)
		ft_putstr(tab[i]);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		rsort_param(argc - 1, &argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
