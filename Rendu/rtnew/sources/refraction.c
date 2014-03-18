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
	double			r;
	double			cos_i;
	double			cos_t2;
	t_ray			r_ray;

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
				r_ray.pos = add(ray_light->pos, prod_val(t, 0.0001));
				r_ray.dir = t;
				if (intersect_mesh(e, &r_ray, &mesh_tmp, NULL))
				{
					tmp = compute_color(e, &r_ray, mesh_tmp, depth + 1, r, NULL);
					tmp.r = tmp.r * exp(mesh->color.r * 0.15 * -r_ray.dist);
					tmp.g = tmp.g * exp(mesh->color.r * 0.15 * -r_ray.dist);
					tmp.b = tmp.b * exp(mesh->color.r * 0.15 * -r_ray.dist);
				}
			}
		}
	}
	return (tmp);
}
