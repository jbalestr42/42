/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:15:55 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/05 18:16:30 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

unsigned int		create_color(int r, int g, int b)
{
	return (b + (g << 8) + (r << 16));
}

unsigned int		get_color_from_img(t_env *e, double it, int max_iter)
{
	unsigned int	color;
	int				i;
	t_img			*img;

	img = &e->pals[e->current_pal];
	i = it / (double)max_iter * (double)img->width;
	i *= img->bpp;
	if (i > 0 && i < img->max_size)
	{
		color = img->img[i + 0];
		color += img->img[i + 1] << 8;
		color += img->img[i + 2] << 16;
	}
	else
		color = 0;
	return (color);
}

void				put_pixel(t_img *img, int x, int y, unsigned int color)
{
	int				i;

	i = y * img->size_line + x * img->bpp;
	if (i > 0 && i < img->max_size)
	{
		img->img[i + 0] = color;
		img->img[i + 1] = (color >> 8);
		img->img[i + 2] = (color >> 16);
	}
}

void				draw(t_env *e)
{
	int				max_iter;
	int				color;
	int				x;
	int				y;

	max_iter = sqrt(ABS(2 * sqrt(ABS(1 - sqrt(5 * e->zoom))))) * 66.5;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			e->u.zx = 0.0;
			e->u.zy = 0.0;
			color = e->fractal_fun[e->current_fractal](e, x, y, max_iter);
			put_pixel(&e->screen, x, y, color);
			y++;
		}
		x++;
	}
}
