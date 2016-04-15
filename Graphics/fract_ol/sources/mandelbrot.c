/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:26:35 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/10 13:48:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int					mandelbrot_tunnel(t_env *e, int x, int y, int mi)
{
	double			nu;

	init_mandelbrot(e, x, y);
	while (++e->u.i < mi)
	{
		e->u.old_zx = e->u.zx;
		e->u.zx = e->u.zx * e->u.zx - e->u.zy * e->u.zy;
		e->u.zy = 2 * e->u.old_zx * e->u.zy;
		e->u.zx += e->u.cx;
		e->u.zy += e->u.cy;
		if (e->u.zx * e->u.zx + e->u.zy * e->u.zy > 1.0)
			break ;
		e->u.i++;
	}
	nu = e->u.i - log(log(sqrt(e->u.zx * e->u.zx + e->u.zy * e->u.zy))) /
		log(2.0);
	return (get_color_from_img(e, nu, mi));
}

int					mandelbrot_broken(t_env *e, int x, int y, int mi)
{
	double			nu;

	init_mandelbrot(e, x, y);
	while (++e->u.i < mi)
	{
		e->u.old_zx = e->u.zx;
		e->u.zx = e->u.zx * e->u.zx - e->u.zy * e->u.zy;
		e->u.zy = 2 * e->u.old_zx * e->u.zy;
		e->u.zx += e->u.cx;
		e->u.zy += e->u.cy;
		if (e->u.zx * e->u.zx + e->u.zy * e->u.zy > 4.0)
			break ;
		e->u.i++;
	}
	nu = e->u.i + 1 - log(log(e->u.zx + e->u.zy)) / log(2);
	return (get_color_from_img(e, nu, mi));
}

int					mandelbrot_bof61(t_env *e, int x, int y, int mi)
{
	init_mandelbrot(e, x, y);
	while (++e->u.i < mi)
	{
		e->u.d = e->u.zx * e->u.zx + e->u.zy * e->u.zy;
		if (e->u.d > 4.0)
		{
			e->u.last_iter = e->u.i;
			break ;
		}
		if (e->u.d < e->u.cld)
		{
			e->u.cld = e->u.d;
			e->u.cln = e->u.i;
		}
		e->u.d = e->u.zx * e->u.zx - e->u.zy * e->u.zy + e->u.cx;
		e->u.zy = 2.0 * e->u.zx * e->u.zy + e->u.cy;
		e->u.zx = e->u.d;
	}
	if (e->u.last_iter == e->u.i)
		return (get_color_from_img(e, e->u.last_iter, mi));
	e->u.last_iter = mi + e->u.cln % 15;
	if (e->u.last_iter >= mi)
		return (get_color_from_img(e, (e->u.last_iter - mi) * 5.0, mi));
	return (get_color_from_img(e, e->u.last_iter, mi));
}

int					mandelbrot_bof60(t_env *e, int x, int y, int mi)
{
	init_mandelbrot(e, x, y);
	while (++e->u.i < mi)
	{
		e->u.d = e->u.zx * e->u.zx + e->u.zy * e->u.zy;
		if (e->u.d > 4.0)
		{
			e->u.last_iter = e->u.i;
			break ;
		}
		if (e->u.d < e->u.cld)
			e->u.cld = e->u.d;
		e->u.d = e->u.zx * e->u.zx - e->u.zy * e->u.zy + e->u.cx;
		e->u.zy = 2.0 * e->u.zx * e->u.zy + e->u.cy;
		e->u.zx = e->u.d;
	}
	if (e->u.last_iter == e->u.i)
		return (get_color_from_img(e, e->u.last_iter, mi));
	if (e->u.cld > 1.0)
		e->u.last_iter = mi + 2;
	e->u.last_iter = mi + ((int)(500 * e->u.cld) % 15);
	if (e->u.last_iter >= mi)
		return (get_color_from_img(e, (e->u.last_iter - mi) * 5.0, mi));
	return (get_color_from_img(e, e->u.last_iter, mi));
}

int					mandelbrot(t_env *e, int x, int y, int mi)
{
	double			nu;

	init_mandelbrot(e, x, y);
	while (++e->u.i < mi)
	{
		e->u.old_zx = e->u.zx;
		e->u.zx = e->u.zx * e->u.zx - e->u.zy * e->u.zy;
		e->u.zy = 2 * e->u.old_zx * e->u.zy;
		e->u.zx += e->u.cx;
		e->u.zy += e->u.cy;
		if (e->u.zx * e->u.zx + e->u.zy * e->u.zy > 4.0)
			break ;
	}
	nu = log(log(sqrt(e->u.zx * e->u.zx + e->u.zy * e->u.zy))) / log(2.0);
	nu = e->u.i - nu;
	if (e->u.i >= mi)
		return (0);
	return (get_color_from_img(e, nu, mi));
}
