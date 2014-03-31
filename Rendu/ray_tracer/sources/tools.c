/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:24:51 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 05:18:25 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

int				cut_space(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] < '!')
		i++;
	return (i);
}

int				check_arg(char *str, int flag)
{
	int			i;
	int			c;

	c = 0;
	i = -1;
	if (str == NULL || !str)
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
		if (str[i] >= 'A' && str[i] <= 'F')
			str[i] += 32;
		if (str[i] >= '0' && str[i] <= '9')
			ccolor = ccolor * 16 + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			ccolor = ccolor * 16 + (str[i] - 'a' + 10);
		i++;
	}
	fin.r = (double)(ccolor % 256) / 255.0;
	fin.g = (double)(ccolor / 256 % 256) / 255.0;
	fin.b = (double)(ccolor / 256 / 256 % 256) / 255.0;
	return (fin);
}
