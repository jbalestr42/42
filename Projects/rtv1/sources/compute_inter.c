/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_inter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 12:06:13 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:51:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

void			create_ray(t_vec *pos, t_ray *ray, t_vec *iv)
{
	t_vec		tmp;

	sub_vec(&ray->dir, pos, iv);
	ray->dist = magnitude(&ray->dir);
	mul_vec_val(&ray->dir, &ray->dir, 1.0f / ray->dist);
	mul_vec_val(&tmp, &ray->dir, 0.0001f);
	add_vec(&ray->ori, &tmp, iv);
}

double			compute_shadow(t_env *e, t_ray *ray, t_object *obj)
{
	int			i;

	i = -1;
	while (++i < e->nb_object)
	{
		if (&e->objects[i] != obj)
		{
			if (e->get_inter[e->objects[i].type](&e->objects[i], ray) > 0)
				return (0.2);
		}
	}
	return (1);
}

/*
** e       : environnement
** inter_v : intersection point
** obj     : nearest object
*/
void			compute_light(t_env *e, t_vec *vi, t_ray *p_ray, t_object *obj)
{
	t_color		col;
	t_ray		ray;
	int			i;
	double		shade;

	i = -1;
	(void)p_ray;
	obj->light.r = obj->color.r * 0.1;
	obj->light.g = obj->color.g * 0.1;
	obj->light.b = obj->color.b * 0.1;
	while (++i < e->nb_light)
	{
		create_ray(&e->lights[i].pos, &ray, vi);
		shade = compute_shadow(e, &ray, obj);
		col = compute_diff(&e->lights[i], obj, vi, shade);
		col.r *= (1 / (0.9 + 0.3 / ray.dist + 0.7 / (ray.dist * ray.dist)));
		col.g *= (1 / (0.9 + 0.3 / ray.dist + 0.7 / (ray.dist * ray.dist)));
		col.b *= (1 / (0.9 + 0.3 / ray.dist + 0.7 / (ray.dist * ray.dist)));
		obj->light.r += col.r;
		obj->light.g += col.g;
		obj->light.b += col.b;
		obj->light.r = obj->light.r > 255 ? 255 : obj->light.r;
		obj->light.g = obj->light.g > 255 ? 255 : obj->light.g;
		obj->light.b = obj->light.b > 255 ? 255 : obj->light.b;
	}
}

double			compute_inter(t_env *e, t_ray *ray, t_object **obj)
{
	double		tmp;
	int			i;

	i = -1;
	ray->dist = MAX_DBL;
	while (++i < e->nb_object)
	{
		tmp = e->get_inter[e->objects[i].type](&e->objects[i], ray);
		if (tmp > 0 && tmp < ray->dist)
		{
			ray->dist = tmp;
			*obj = &e->objects[i];
		}
	}
	if (ray->dist < MAX_DBL)
		return (ray->dist);
	return (0);
}
