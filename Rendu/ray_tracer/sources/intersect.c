/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:40:56 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 19:08:53 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"
#include "perlin.h"

int				compute_shadow(t_env *e, t_ray *ray, t_ray *oldray,
								t_mesh *mesh)
{
	int			i;
	t_ray		tmp;

	i = -1;
	while (++i < e->nb_mesh)
	{
		if (&e->meshes[i] != mesh && e->meshes[i].type != T_PLAN)
		{
			tmp.pos = add(oldray->pos, prod_val(oldray->dir, oldray->dist));
			tmp.dir = ray->dir;
			if (e->inter_tab[e->meshes[i].type](&e->meshes[i],
												&tmp, &tmp) > 0.0001)
				return (1);
		}
	}
	return (0);
}

static t_color	attenuate_color(t_env *e, double dist, t_color pix)
{
	if (e->attenuate)
	{
		pix = prod_col_val(pix, 1 / (0.9 + 0.9 / dist + 0.9 / (dist * dist)));
		pix.r = 1.0 - exp(pix.r * -1.5);
		pix.g = 1.0 - exp(pix.g * -1.5);
		pix.b = 1.0 - exp(pix.b * -1.5);
	}
	return (pix);
}

t_color			compute_color(t_env *e, t_compute c, int depth, double refr)
{
	t_color		pix;
	int			i;

	i = -1;
	c.ray_light.pos = c.inter;
	pix = e->effects[c.mesh->mat.type](c.inter, c.mesh->color,
										c.mesh->mat.col1, 2);
	pix = prod_col_val(pix, e->ambient);
	while (++i < e->nb_light)
	{
		c.ray_light.dir = sub(e->lights[i].pos, c.ray_light.pos);
		if (!compute_shadow(e, &c.ray_light, &c.ray, c.mesh))
		{
			c.ray_light.dist = magnitude(c.ray_light.dir);
			pix = add_col_col(pix, diffuse(e, &e->lights[i], c.mesh,
											&c.ray_light));
			pix = add_col_col(pix, specular(e, &e->lights[i], c));
		}
	}
	pix = add_col_col(pix, reflection(e, c, depth, refr));
	pix = add_col_col(pix, refraction(e, c, depth, refr));
	pix = attenuate_color(e, c.ray_light.dist, pix);
	pix = cell_shading(e, pix);
	return (pix);
}

int				intersect_mesh(t_env *e, t_ray *ray, t_mesh **mesh,
								t_vertex *m_ver)
{
	t_ray		tmp_r;
	int			i;
	double		tmp;

	i = -1;
	ray->dist = MAX_DBL;
	while (++i < e->nb_mesh)
	{
		if ((tmp = e->inter_tab[e->meshes[i].type](&e->meshes[i], ray, &tmp_r)))
		{
			if (tmp >= 0 && tmp < ray->dist)
			{
				ray->dist = tmp;
				*mesh = &e->meshes[i];
				if (m_ver)
				{
					*m_ver = add(tmp_r.pos, prod_val(tmp_r.dir, ray->dist));
					(*m_ver).x += perlin_ocean(e, *m_ver, (*mesh)->type, INTER);
				}
			}
		}
	}
	if (ray->dist < MAX_DBL)
		return (1);
	return (0);
}
