/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:24:51 by glasset           #+#    #+#             */
/*   Updated: 2014/03/19 15:39:01 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

void		error_p(char *s1, char *s2, int l)
{
	write(1, "l", 1);
	ft_putnbr(l);
	write(1, ": ", 2);
	write(1, s2, ft_strlen(s2));
	write(1, ": \"", 3);
	write(1, s1, ft_strlen(s1));
	write(1, "\"\n", 2);
}

f			*funct(void)
{
	f		*ft;

	ft = malloc(sizeof(ft) * 4);
	ft[0] = &comment;
	ft[1] = &information;
	ft[2] = &init_mesh;
	ft[3] = &light;
	return (ft);
}

int			cut_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] < '!')
		i++;
	return (i);
}

int			comment_b(t_env *e, char *str)
{
	(void)e;
	(void)str;
	return (1);
}

int			check_arg(char *str, int flag)
{
	int		i;
	int		c;

	c = 0;
	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (str[i] == '.' || str[i] == ';' || str[i] == ' ' || str[i] == '-')
			;
		else if (str[i] >= '0' || str[i] <= '9')
			c = 1;
		else
			return (-1);
	}
	if (c == 0)
		return (-1);
	if (flag == 1)
	{
		if (ft_atod(str) > 1.0)
			return (-1);
	}
	return (0);
}

t_color			get_color(char *str)
{
	t_color		fin;
	int			i;
	int			ccolor;

	ccolor = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ccolor =  ccolor * 16 + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			ccolor = ccolor * 16 + (str[i] - 'a' + 10);
		i++;
	}
	fin.r = (double)(ccolor % 256) / 255.0;
	fin.g = (double)(ccolor / 256 % 256) / 255.0;
	fin.b = (double)(ccolor / 256 / 256 % 256 ) / 255.0;
	return (fin);
}
