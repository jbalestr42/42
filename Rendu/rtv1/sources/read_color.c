/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 10:42:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:52:39 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "ray_tracer.h"

int					ft_strlen_tab(char **tab)
{
	int				len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void				free_split(char **s)
{
	int				i;

	i = -1;
	while (s[++i])
		free(s[i]);
}

static int			ft_ishex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

static int			htoi(char *hex, int l)
{
	if (*hex == 0)
		return (l);
	return (htoi(hex + 1, l * 16 + ft_ishex(*hex)));
}

t_color				read_color(t_env *e, char *str)
{
	t_color			col;
	int				color;
	unsigned int	coloru;

	color = 0;
	str += 2;
	color = htoi(str, 0);
	coloru = mlx_get_color_value(e->mlx, color);
	col.r = (unsigned char)(coloru);
	col.g = (unsigned char)(coloru >> 8);
	col.b = (unsigned char)(coloru >> 16);
	return (col);
}
