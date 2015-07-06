/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:18:10 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 19:08:45 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"
#include "perlin.h"

t_color			specular(t_env *e, t_light *light, t_compute c)
{
	t_color		col;
	t_vector	normal;
	t_vector	r;
	double		d;
	double		spec;

	col = init_color(0.0, 0.0, 0.0);
	if (c.mesh->spec > 0.0001)
	{
		normal = e->normals[c.mesh->type](c.mesh, &c.ray_light.pos);
		c.ray_light.dir.x += perlin_ocean(e, c.ray_light.pos,
											c.mesh->type, SPE);
		r = sub(c.ray_light.dir,
				prod_val(normal, 2.0 * dot(c.ray_light.dir, normal)));
		d = dot(c.ray.dir, normalize(r));
		if (d > 0.0001)
		{
			spec = pow(d, 30) * c.mesh->spec;
			col = prod_col_val(light->color, spec);
		}
	}
	return (col);
}
