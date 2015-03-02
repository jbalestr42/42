/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:18:37 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 05:17:40 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ray_tracer.h"

static t_color		final_color(t_refr v, double dist)
{
	v.tmp.r = v.tmp.r * exp(v.col.r * 0.15 * -dist);
	v.tmp.g = v.tmp.g * exp(v.col.g * 0.15 * -dist);
	v.tmp.b = v.tmp.b * exp(v.col.b * 0.15 * -dist);
	return (v.tmp);
}

t_color				refraction(t_env *e, t_compute c, int depth, double refr)
{
	t_refr			v;

	v.tmp = init_color(0.0, 0.0, 0.0);
	if (c.mesh->type == T_PLAN || c.mesh->type == T_TRIANGLE
		|| c.mesh->refr < 0.0001 || depth >= 1)
		return (v.tmp);
	v.r = refr / c.mesh->refr;
	v.n = prod_val(e->normals[c.mesh->type](c.mesh, &c.ray_light.pos),
				c.ray.dist);
	v.cos_i = -dot(v.n, c.ray.dir);
	v.cos_t2 = 1.0f - (v.r * v.r * (1.0f - (v.cos_i * v.cos_i)));
	if (v.cos_t2 <= 0.0)
		return (v.tmp);
	v.t = add(prod_val(c.ray.dir, v.r),
				prod_val(v.n, v.r * v.cos_i - sqrt(v.cos_t2)));
	c.ray.pos = add(c.ray.pos, prod_val(c.ray.dir, c.ray.dist));
	c.ray.dir = v.t;
	if (!(intersect_mesh(e, &c.ray, &c.mesh, &c.inter)))
		return (v.tmp);
	v.tmp = compute_color(e, c, depth + 1, v.r);
	v.col = e->effects[c.mesh->mat.type](c.ray.pos,
										c.mesh->color, c.mesh->mat.col1, 2);
	v.tmp = final_color(v, c.ray.dist);
	return (v.tmp);
}
