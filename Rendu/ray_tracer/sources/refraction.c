/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:18:37 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/13 13:54:25 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ray_tracer.h"

t_color				refraction(t_env *e, t_mesh *mesh, t_ray *ray_light, t_ray *ray, int depth, double refr)
{
	t_mesh			*mesh_tmp;
	t_color			tmp;
	t_vector		n;
	t_vector		t;
	t_vertex		inter;
	t_color			col;
	double			r;
	double			cos_i;
	double			cos_t2;
	t_ray			new_r;

	tmp.r = 0;
	tmp.g = 0;
	tmp.b = 0;
	if (mesh->type == T_SPHERE)
	{
		if (depth < 1)
		{
			r = refr / mesh->refr;
			n = prod_val(e->normals[mesh->type](mesh, &ray_light->pos), ray->dist);
			cos_i = -dot(n, ray->dir);
			cos_t2 = 1.0f - (r * r * (1.0f - (cos_i * cos_i)));
			if (cos_t2 > 0.0)
			{
				t = add(prod_val(ray->dir, r), prod_val(n, r * cos_i - sqrt(cos_t2)));
				new_r.pos = add(ray->pos, prod_val(ray->dir, ray->dist));
				new_r.dir = t;
				if (intersect_mesh(e, &new_r, &mesh_tmp, &inter))
				{
					tmp = compute_color(e, &new_r, mesh_tmp, depth + 1, r, &inter);
					if (mesh_tmp->type == T_SPHERE) // if perlin
						col = perlin_marble(inter.x, inter.y, inter.z);
					else
						col = mesh_tmp->color;
					tmp.r = tmp.r * exp(col.r * 0.15 * -new_r.dist);
					tmp.g = tmp.g * exp(col.g * 0.15 * -new_r.dist);
					tmp.b = tmp.b * exp(col.b * 0.15 * -new_r.dist);
				}
			}
		}
	}
	return (tmp);
}
