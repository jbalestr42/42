/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:17:13 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/13 13:52:01 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"

t_color			reflection(t_env *e, t_mesh *mesh, t_ray *ray_light, t_ray *ray, int depth, double refr)
{
	t_vector	n;
	t_vector	r;
	t_ray		new_r;
	t_mesh		*mesh_tmp;
	t_color		tmp;

	tmp.r = 0.0;
	tmp.g = 0.0;
	tmp.b = 0.0;
	if (mesh->refl > 0.0)
	{
		n = e->normals[mesh->type](mesh, &ray_light->pos);
		r = sub(ray->dir, prod_val(n, 2.0 * dot(ray->dir, n)));
		if (depth < 1)
		{
			new_r.pos = add(ray_light->pos, prod_val(r, 0.0001));
			new_r.dir = r;
			if (intersect_mesh(e, &new_r, &mesh_tmp, NULL))
			{
				tmp = compute_color(e, &new_r, mesh_tmp, depth + 1, refr, NULL);
				tmp.r = tmp.r * 1.0 * mesh->color.r;
				tmp.g = tmp.g * 1.0 * mesh->color.g;
				tmp.b = tmp.b * 1.0 * mesh->color.b;
			}
		}
	}
	return (tmp);
}
