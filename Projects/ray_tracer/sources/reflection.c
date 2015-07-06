/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:17:13 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 20:01:26 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"
#include "perlin.h"

t_color			reflection(t_env *e, t_compute c, int depth, double refr)
{
	t_vector	n;
	t_vector	r;
	t_color		tmp;
	t_color		col;
	double		refl;

	tmp = init_color(0.0, 0.0, 0.0);
	if (c.mesh->refl < 0.0001 || depth >= 2)
		return (tmp);
	n = e->normals[c.mesh->type](c.mesh, &c.ray_light.pos);
	r = sub(c.ray.dir, prod_val(n, 2.0 * dot(c.ray.dir, n)));
	c.ray.pos = add(c.ray.pos, prod_val(c.ray.dir, c.ray.dist));
	c.ray.pos.x += perlin_ocean(e, c.ray.pos, c.mesh->type, INTER);
	c.ray.dir = r;
	if (intersect_mesh(e, &c.ray, &c.mesh, &c.inter))
	{
		refl = c.mesh->refl;
		tmp = compute_color(e, c, depth + 1, refr);
		col = e->effects[c.mesh->mat.type](c.inter, c.mesh->color,
											c.mesh->mat.col1, 2);
		tmp.r = tmp.r * refl * col.r;
		tmp.g = tmp.g * refl * col.g;
		tmp.b = tmp.b * refl * col.b;
	}
	return (tmp);
}
