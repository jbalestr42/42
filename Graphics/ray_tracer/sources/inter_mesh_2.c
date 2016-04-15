/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_mesh_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:14:22 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 16:51:22 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

double			inter_parabole(t_mesh *mesh, t_ray *ray, t_ray *m_ray)
{
	t_parabole	*p;
	t_vector	pos;
	t_vector	dir;
	double		abc[3];
	double		d;

	pos = transform_pos(mesh->result, &ray->pos);
	dir = transform_dir(mesh->result, &ray->dir);
	p = &mesh->prim.parabole;
	abc[0] = pow(dir.x, 2) + pow(dir.y, 2);
	abc[1] = (2 * (dir.x * pos.x + dir.y * pos.y)) - (dir.z * tan(p->coeff));
	abc[2] = pow(pos.x, 2) + pow(pos.y, 2) - (pos.z * tan(p->coeff));
	d = determinant(abc[0], abc[1], abc[2]);
	if (d >= 0.0001)
	{
		m_ray->pos = pos;
		m_ray->dir = dir;
		return (d);
	}
	return (-1);
}

double			inter_hyperbole(t_mesh *mesh, t_ray *ray, t_ray *m_ray)
{
	t_hyperbole	*h;
	t_vector	pos;
	t_vector	dir;
	double		abc[3];
	double		d;

	pos = transform_pos(mesh->result, &ray->pos);
	dir = transform_dir(mesh->result, &ray->dir);
	h = &mesh->prim.hyperbole;
	abc[0] = pow(dir.x, 2) + pow(dir.y, 2)
			- (pow(dir.z, 2) * pow(tan(h->coeff), 2));
	abc[1] = (2 * (dir.x * pos.x + dir.y * pos.y))
			- (2 * (dir.z * pos.z * pow(tan(h->coeff), 2)));
	abc[2] = pow(pos.x, 2) + pow(pos.y, 2)
			- (pow(pos.z, 2) * pow(tan(h->coeff), 2)) - h->open;
	d = determinant(abc[0], abc[1], abc[2]);
	if (d >= 0.0001)
	{
		m_ray->pos = pos;
		m_ray->dir = dir;
		return (d);
	}
	return (-1);
}

double			inter_triangle(t_mesh *mesh, t_ray *ray, t_ray *m_ray)
{
	t_vector	w;
	t_vector	tmp;
	t_vector	dir;
	t_vertex	pos;
	double		abdt[4];

	pos = transform_pos(mesh->result, &ray->pos);
	dir = transform_dir(mesh->result, &ray->dir);
	if (!(abdt[2] = -dot(dir, mesh->prim.triangle.normal)))
		return (0);
	w.x = pos.x - mesh->prim.triangle.v1.x;
	w.y = pos.y - mesh->prim.triangle.v1.y;
	w.z = pos.z - mesh->prim.triangle.v1.z;
	abdt[0] = -dot(cross(w, mesh->prim.triangle.v3), dir) / abdt[2];
	tmp = cross(mesh->prim.triangle.v2, w);
	abdt[1] = -dot(tmp, dir) / abdt[2];
	tmp = cross(mesh->prim.triangle.v2, mesh->prim.triangle.v3);
	abdt[3] = dot(tmp, w) / abdt[2];
	if (abdt[0] > 0.0 && abdt[1] > 0.0 && (abdt[0] + abdt[1]) <= 1.0)
	{
		m_ray->pos = pos;
		m_ray->dir = dir;
		return (abdt[3]);
	}
	return (0);
}
