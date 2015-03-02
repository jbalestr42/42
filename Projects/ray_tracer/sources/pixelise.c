/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:12:22 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 19:09:08 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ray_tracer.h"
#include "perlin.h"

static void		change_color_pixelise_pp(t_env *e, int x, int y, int size)
{
	int			i;
	int			j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			put_pixel_pp(e, x + i, y + j);
	}
}

static void		compute_color_pp(t_env *e, t_color *tab, int size)
{
	int			i;
	t_color		tmp;

	tmp = init_color(0.0, 0.0, 0.0);
	i = -1;
	size = size * size;
	while (++i < size)
		tmp = add_col_col(tmp, tab[i]);
	e->color.r = tmp.r / size;
	e->color.g = tmp.g / size;
	e->color.b = tmp.b / size;
}

void			pixelise_pp(t_env *e, int size)
{
	int			x;
	int			y;
	int			i;
	int			j;
	t_color		tab[size * size];

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT - (HEIGHT % size))
		{
			i = -1;
			while (++i < size)
			{
				j = -1;
				while (++j < size)
					tab[i + size * j] = get_color_pp(e, x + i, y + j);
			}
			compute_color_pp(e, tab, size);
			change_color_pixelise_pp(e, x, y, size);
			y = y + size;
		}
		x = x + size;
	}
}

void			escape_screen(t_env *e)
{
	int			size;

	size = 1;
	while (++size < 32)
	{
		pixelise_pp(e, size);
		expose_hook(e);
		usleep(7000);
	}
}
