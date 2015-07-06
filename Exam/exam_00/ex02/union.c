/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 15:14:28 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 18:07:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_cmp(char c, char *s, int index)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	if (i == index)
		write(1, &s[i], 1);
}

void	ft_union(char *s1, char *s2)
{
	int		i;
	int		j;

	i = -1;
	while (s1[++i])
		ft_cmp(s1[i], s1, i);
	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s1[j])
		{
			if (s2[i] == s1[j])
				break ;
			j++;
		}
		if (!s1[j])
			ft_cmp(s2[i], s2, i);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
