/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:37:27 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/27 11:48:11 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"
#include "perlin.h"

void			put_pixel_pp(t_env *e, int x, int y)
{
	int			k;

	k = y * e->screens[RAY_TRACE].background.size_line
		+ (x * e->screens[RAY_TRACE].background.bpp);
	if (k >= 0 && k < e->screens[RAY_TRACE].background.max_size)
	{
		e->color.r = e->color.r > 1 ? 1 : e->color.r;
		e->color.g = e->color.g > 1 ? 1 : e->color.g;
		e->color.b = e->color.b > 1 ? 1 : e->color.b;
		e->color.r = e->color.r < 0 ? 0 : e->color.r;
		e->color.g = e->color.g < 0 ? 0 : e->color.g;
		e->color.b = e->color.b < 0 ? 0 : e->color.b;
		e->screens[RAY_TRACE].background.img[k] = (int)(e->color.r * 255);
		e->screens[RAY_TRACE].background.img[k + 1] = (int)(e->color.g * 255);
		e->screens[RAY_TRACE].background.img[k + 2] = (int)(e->color.b * 255);
	}
}

static void		change_color_pp(t_env *e, int type)
{
	double		tmp;

	tmp = (e->color.r + e->color.g + e->color.b) / 3.0;
	if (type == B_AND_W)
	{
		e->color.r = tmp;
		e->color.g = tmp;
		e->color.b = tmp;
	}
	else if (type == SEPIA)
	{
		e->color.r = tmp * 0.2;
		e->color.g = tmp * 0.6;
		e->color.b = tmp * 1.1;
	}
	else if (type == NEGATIVE)
	{
		e->color.r = 1.0 - e->color.r;
		e->color.g = 1.0 - e->color.g;
		e->color.b = 1.0 - e->color.b;
	}
}

t_color			get_color_pp(t_env *e, int x, int y)
{
	int			k;

	k = y * e->screens[RAY_TRACE].background.size_line
		+ (x * e->screens[RAY_TRACE].background.bpp);
	if (k >= 0 && k < e->screens[RAY_TRACE].background.max_size)
	{
		e->color.r = (unsigned char)e->screens[RAY_TRACE].background.img[k]
			/ 255.0;
		e->color.g = (unsigned char)e->screens[RAY_TRACE].background.img[k + 1]
			/ 255.0;
		e->color.b = (unsigned char)e->screens[RAY_TRACE].background.img[k + 2]
			/ 255.0;
	}
	return (e->color);
}

void			post_processing(t_env *e, int type)
{
	int			x;
	int			y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			get_color_pp(e, x, y);
			change_color_pp(e, type);
			put_pixel_pp(e, x, y);
		}
	}
}
