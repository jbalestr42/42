/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:18:35 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 11:09:15 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"

void			compute_up_left(t_env *e)
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

void			compute_ray(t_env *e, t_ray *r, int x, int y)
{
	t_vector	v;

	r->pos = e->cam.pos;
	v = prod_val(e->cam.right, (double)X_INDENT * x);
	v = sub(v, prod_val(e->cam.up, (double)Y_INDENT * y));
	v = add(sub(e->up_left, r->pos), v);
	r->dir = normalize(v);
}

void			launch_ray(t_env *e, int x, int y)
{
	t_mesh		*mesh;
	t_vertex	inter;
	t_ray		ray;
	t_compute	c;

	mesh = NULL;
	compute_ray(e, &ray, x, y);
	if (intersect_mesh(e, &ray, &mesh, &inter))
	{
		if (e->aa_active)
		{
			e->aa.x = x;
			e->aa.y = y;
			e->color = compute_aa(e, &ray, &mesh, &inter);
		}
		else
		{
			c = init_compute(ray, mesh, inter, ray);
			e->color = compute_color(e, c, 0, 1.0);
		}
	}
	else
		e->color = init_color(0.0, 0.0, 0.0);
}
