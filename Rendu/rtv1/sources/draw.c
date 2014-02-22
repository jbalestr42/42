/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 11:56:50 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:51:05 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "ray_tracer.h"

static void		compute_inter_point(t_ray *ray, t_vec *inter_v)
{
	inter_v->x = ray->ori.x + ray->dist * ray->dir.x;
	inter_v->y = ray->ori.y + ray->dist * ray->dir.y;
	inter_v->z = ray->ori.z + ray->dist * ray->dir.z;
}

static void		compute_ray(t_env *e, t_ray *ray, int x, int y)
{
	t_vec		tmpx;
	t_vec		tmpy;
	t_vec		tmp;
	t_vec		tmplast;

	mul_vec_val(&tmpx, &e->cam.right, e->x_ratio * x);
	mul_vec_val(&tmpy, &e->cam.down, e->y_ratio * y);
	sub_vec(&tmp, &tmpx, &tmpy);
	sub_vec(&tmplast, &e->pos_plan, &ray->ori);
	add_vec(&ray->dir, &tmplast, &tmp);
}

static void		put_pixel(t_env *e, int x, int y, t_object *obj)
{
	int			k;

	k = y * e->screen.size_line + (x * e->screen.bpp);
	if (k >= 0 && k < e->screen.max_size)
	{
		if (obj)
		{
			e->screen.img[k] = obj->light.r;
			e->screen.img[k + 1] = obj->light.g;
			e->screen.img[k + 2] = obj->light.b;
		}
		else
		{
			e->screen.img[k] = 0;
			e->screen.img[k + 1] = 0;
			e->screen.img[k + 2] = 0;
		}
	}
}

void			draw_view(t_env *e)
{
	t_object	*obj;
	t_ray		ray;
	t_vec		iv;
	int			x;
	int			y;

	x = -1;
	ray.ori = e->cam.ori;
	obj = NULL;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			compute_ray(e, &ray, x, y);
			if (compute_inter(e, &ray, &obj) == 0)
				put_pixel(e, x, y, NULL);
			else
			{
				compute_inter_point(&ray, &iv);
				compute_light(e, &iv, &ray, obj);
				put_pixel(e, x, y, obj);
			}
		}
	}
}
