/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:57:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 05:14:04 by mdebelle         ###   ########.fr       */
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
