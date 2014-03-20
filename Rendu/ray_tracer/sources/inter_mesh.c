/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:57:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/19 17:10:05 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

double			inter_sphere(t_mesh *mesh, t_ray *ray, t_ray *m_ray)
{
	t_sphere	*sphere;
	t_vector	pos;
	t_vector	dir;
	double		abc[3];
	double		d;

	pos = transform_pos(mesh->result, &ray->pos);
	dir = transform_dir(mesh->result, &ray->dir);
	sphere = &mesh->prim.sphere;
	abc[0] = square_length(dir);
	abc[1] = 2 * dot(dir, pos);
	abc[2] = square_length(pos) - pow(sphere->radius, 2);
	d = determinant(abc[0], abc[1], abc[2]);
	if (d >= 0.0001)
	{
		m_ray->pos = pos;
		m_ray->dir = dir;
		return (d);
	}
	return (-1);
}

double			inter_plan(t_mesh *mesh, t_ray *ray, t_ray *m_ray)
{
	t_plan		*plan;
	t_vector	pos;
	t_vector	dir;
	double		d;

	pos = transform_pos(mesh->result, &ray->pos);
	dir = transform_dir(mesh->result, &ray->dir);
	plan = &mesh->prim.plan;
	d = -(dot(plan->normal, pos))
		/ dot(plan->normal, dir);
	if (d >= 0.0001)
	{
		m_ray->pos = pos;
		m_ray->dir = dir;
		return (d);
	}
	return (-1);
}

double			inter_cylinder(t_mesh *mesh, t_ray *ray, t_ray *m_ray)
{
	t_cylinder	*cyl;
	t_vector	pos;
	t_vector	dir;
	double		abc[3];
	double		d;

	pos = transform_pos(mesh->result, &ray->pos);
	dir = transform_dir(mesh->result, &ray->dir);
	cyl = &mesh->prim.cylinder;
	abc[0] = pow(dir.x, 2) + pow(dir.y, 2);
	abc[1] = 2 * (dir.x * pos.x + dir.y * pos.y);
	abc[2] = pow(pos.x, 2) + pow(pos.y, 2) - pow(cyl->radius, 2);
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

double			inter_cone(t_mesh *mesh, t_ray *ray, t_ray *m_ray)
{
	t_cone		*con;
	t_vector	pos;
	t_vector	dir;
	double		abc[3];
	double		d;

	pos = transform_pos(mesh->result, &ray->pos);
	dir = transform_dir(mesh->result, &ray->dir);
	con = &mesh->prim.cone;
	abc[0] = pow(dir.x, 2) + pow(dir.y, 2)
				- pow(dir.z, 2) * pow(tan(con->coeff), 2);
	abc[1] = (2 * (dir.x * pos.x + dir.y * pos.y))
				- (2 * dir.z * pos.z * pow(tan(con->coeff), 2));
	abc[2] = pow(pos.x, 2) + pow(pos.y, 2)
				- (pow(pos.z, 2) * pow(tan(con->coeff), 2));
	d = determinant(abc[0], abc[1], abc[2]);
	if (d >= 0.0001)
	{
		m_ray->pos = pos;
		m_ray->dir = dir;
		return (d);
	}
	return (-1);
}

double			inter_triangle(t_mesh *mesh, t_ray *ray)
{
	t_triangle	*tri;
	t_vector	w;
	t_vector	tmp;
	t_vector	dir;
	t_vertex	pos;
	double		d;
	double		a;
	double		b;
	double		t;

	pos = transform_pos(mesh->result, &ray->pos);
	dir = transform_dir(mesh->result, &ray->dir);
	tri = &mesh->prim.triangle;
	if (!(d = -dot(dir, tri->normal)))
		return (0);
	w.x = pos.x - tri->v1.x;
	w.y = pos.y - tri->v1.y;
	w.z = pos.z - tri->v1.z;
	tmp = cross(w, tri->v3);
	a = -dot(tmp, dir) / d;
	tmp = cross(tri->v2, w);
	b = -dot(tmp, dir) / d;
	tmp = cross(tri->v2, tri->v3);
	t = dot(tmp, w) / d;
	if (a > 0 && b > 0 && a + b <= 1)
		return (t);
	return (0);
}
