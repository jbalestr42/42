/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:33:07 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 19:09:26 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"
#include "ray_tracer.h"

t_color			diffuse(t_env *e, t_light *light, t_mesh *m, t_ray *ray)
{
	t_color		col;
	double		d;

	col = init_color(0.0, 0.0, 0.0);
	if (m->diff > 0.0001)
	{
		ray->dir.z += perlin_ocean(e, ray->pos, m->type, DIF);
		d = dot(normalize(ray->dir), e->normals[m->type](m, &ray->pos));
		if (d > 0.0001)
		{
			col = e->effects[m->mat.type](ray->pos, m->color, m->mat.col1, 2);
			col = prod_col_col(col, light->color);
			col = prod_col_val(col, d * m->diff);
		}
	}
	return (col);
}
