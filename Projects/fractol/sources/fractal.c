/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:26:38 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/05 18:10:38 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>

int				julia(t_env *e, int x, int y, int max_iterations)
{
	e->u.cx = e->julia_cx;
	e->u.cy = e->julia_cy;
	e->u.zx = 1.6 * (x - HALF_WIDTH) / (e->zoom_width) + e->offset_x;
	e->u.zy = (y - HALF_HEIGHT) / (e->zoom_height) + e->offset_y;
	e->u.i = 1;
	while (e->u.i < max_iterations)
	{
		e->u.zxx = e->u.zx * e->u.zx;
		e->u.zyy = e->u.zy * e->u.zy;
		e->u.old_zx = e->u.zx;
		e->u.old_zy = e->u.zy;
		e->u.zx = e->u.zxx - e->u.zyy + e->u.cx;
		e->u.zy = 2 * e->u.zy * e->u.old_zx + e->u.cy;
		if (e->u.zx == e->u.old_zx && e->u.zy == e->u.old_zy)
			e->u.i = max_iterations - 1;
		if (e->u.zxx + e->u.zyy > 4.0)
			break ;
		e->u.i++;
	}
	if (e->u.i >= max_iterations)
		return (0);
	return (get_color_from_img(e, e->u.i, max_iterations));
}

int				burning_ship(t_env *e, int x, int y, int max_iterations)
{
	e->u.cx = 1.5 * (x - HALF_WIDTH) / (e->zoom_width) + e->offset_x + 0.5;
	e->u.cy = (y - HALF_HEIGHT) / (e->zoom_height) + e->offset_y - 0.4;
	e->u.i = 1;
	while (e->u.i < max_iterations)
	{
		e->u.zxx = e->u.zx * e->u.zx;
		e->u.zyy = e->u.zy * e->u.zy;
		e->u.old_zx = e->u.zx;
		e->u.zx = e->u.zx * e->u.zx - e->u.zy * e->u.zy - e->u.cx;
		e->u.zy = 2 * fabs(e->u.zy * e->u.old_zx) + e->u.cy;
		if (e->u.zxx + e->u.zyy > 4.0)
			break ;
		e->u.i++;
	}
	if (e->u.i >= max_iterations)
		return (0);
	return (get_color_from_img(e, e->u.i, max_iterations));
}

int				newton(t_env *e, int x, int y, int max_iterations)
{
	e->u.cx = 1.5 * (x - HALF_WIDTH) / (e->zoom * HALF_WIDTH) + e->offset_x;
	e->u.cy = (y - HALF_HEIGHT) / (e->zoom * HALF_HEIGHT) + e->offset_y;
	e->u.zx = e->u.cx;
	e->u.zy = e->u.cy;
	e->u.i = 0;
	while (++e->u.i < max_iterations)
	{
		e->u.zxx = e->u.zx * e->u.zx;
		e->u.zyy = e->u.zy * e->u.zy;
		e->u.d = 3.0 * ((e->u.zxx - e->u.zyy) * (e->u.zxx - e->u.zyy) +
				4.0 * e->u.zxx * e->u.zyy);
		if (e->u.d == 0.0)
		{
			e->u.d = 0.000001;
			break ;
		}
		e->u.old_zx = e->u.zx;
		e->u.zx = (2.0 / 3.0) * e->u.zx + (e->u.zxx - e->u.zyy) / e->u.d;
		e->u.zy = (2.0 / 3.0) * e->u.zy - 2.0 * e->u.old_zx * e->u.zy / e->u.d;
	}
	if (e->u.zx > 0.0)
		return (create_color(255, 0, 0));
	else if ((e->u.zx < -0.3) && (e->u.zy > 0.0))
		return (create_color(0, 255, 0));
	return (create_color(0, 0, 255));
}
