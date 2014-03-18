/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:33:07 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/13 13:39:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

static void		diff_col(t_color *c, t_color *objc, t_color *lic, double diff)
{
	c->r = diff * lic->r * objc->r;
	c->g = diff * lic->g * objc->g;
	c->b = diff * lic->b * objc->b;
}

t_color			diffuse(t_env *e, t_light *light, t_mesh *mesh, t_ray *ray)
{
	t_color		col;
	double		d;
	double		diff;

	col.r = 0.0;
	col.g = 0.0;
	col.b = 0.0;
	d = dot(normalize(ray->dir), e->normals[mesh->type](mesh, &ray->pos));
	if (d > 0.0)
	{
		diff = d * mesh->diff;
		diff_col(&col, &mesh->color, &light->color, diff);
	}
	return (col);
}
