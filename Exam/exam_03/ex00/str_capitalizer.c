/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 14:33:33 by exam              #+#    #+#             */
/*   Updated: 2014/02/20 14:52:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		parse_str(char *s)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		{
			write(1, &s[i], 1);
			i++;
		}
		if (!s[i])
			return ;
		if (s[i] >= 'a' && s[i] <= 'z')
			c = s[i++] - 32;
		else
			c = s[i++];
		write(1, &c, 1);
		while (s[i] && s[i] != ' ' && s[i] != '\t')
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				c = s[i] + 32;
			else
				c = s[i];
			write(1, &c, 1);
			i++;
		}
	}
}

void		str_capitalizer(int nb, char **tab)
{
	int		i;

	i = -1;
	while (++i < nb)
	{
		parse_str(tab[i]);
		write(1, "\n", 1);
	}
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		str_capitalizer(argc - 1, &argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
