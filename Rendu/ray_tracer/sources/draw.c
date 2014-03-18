/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:18:35 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/12 17:52:47 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h> // delete si on deplace la fonction de refresh
#include <stdlib.h>
#include "ray_tracer.h"

static void		compute_up_left(t_env *e)
{
	t_vector	tmp;

	e->cam.dir = normalize(sub(e->look_at_point, e->cam.pos));
	e->cam.right = normalize(cross(init_vec(0, 1, 0.000001), e->cam.dir));
	e->cam.up = normalize(cross(e->cam.dir, e->cam.right));
	tmp = prod_val(e->cam.dir, 1.0);
	tmp = add(tmp, prod_val(e->cam.up, 0.35 / 2.0));
	tmp = sub(tmp, prod_val(e->cam.right, 0.5 / 2.0));
	tmp = add(e->cam.pos, tmp);
	e->up_left = tmp;
}

static void		compute_ray(t_env *e, t_ray *r, int x, int y)
{
	t_vector	v;

	r->pos = e->cam.pos;
	v = prod_val(e->cam.right, (double)X_INDENT * x);
	v = sub(v, prod_val(e->cam.up, (double)Y_INDENT * y));
	v = add(sub(e->up_left, r->pos), v);
	r->dir = normalize(v);
}

static void		put_pixel(t_env *e, int x, int y)
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

void			draw_image(t_env *e)
{
	t_mesh		*mesh;
	t_vertex	inter;
	t_ray		ray;
	t_color		tmp;
	t_color		col;
	int			x;
	int			y;

	x = -1;
	mesh = NULL;
	compute_up_left(e);
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			compute_ray(e, &ray, x, y);
			if (intersect_mesh(e, &ray, &mesh, &inter))
			{
				// anti aliasing
				if (0)
				{
					col.r = 0;
					col.g = 0;
					col.b = 0;
					int		aax = -2;
					while (aax < 2)
					{
						int aay = -2;
						while (aay < 2)
						{
							compute_ray(e, &ray, x - aax, y + aay);
							if (intersect_mesh(e, &ray, &mesh, &inter))
							{
								tmp = compute_color(e, &ray, mesh, 0, 1.0, &inter);
								col.r += tmp.r;
								col.g += tmp.g;
								col.b += tmp.b;
							}
							aay++;
						}
						aax++;
					}
					e->color.r = col.r / 16;
					e->color.g = col.g / 16;
					e->color.b = col.b / 16;
				}
				else
					e->color = compute_color(e, &ray, mesh, 0, 1.0, &inter);
			}
			else
			{
				e->color.r = 0x0;
				e->color.g = 0x0;
				e->color.b = 0x0;
			}
			put_pixel(e, x, y);
		}
		if (e->progressive_load)
			refresh_load(e, x / (double)WIDTH);
		ft_putnbr(x / (double)WIDTH * 100);
		ft_putstr("%\n");
	}
	ft_putstr("100%\n");
	e->cur_screen = RAY_TRACE;
}
