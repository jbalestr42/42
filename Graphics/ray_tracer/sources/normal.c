/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:34:43 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 05:15:59 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_vertex		normal_cone(t_mesh *mesh, t_vertex *v)
{
	t_vector	dir;
	double		tmp;

	tmp = v->z;
	v->z = -mesh->prim.cone.coeff * v->z;
	dir = transform_normal(mesh->result, v);
	v->z = tmp;
	return (normalize(dir));
}

t_vertex		normal_cylinder(t_mesh *mesh, t_vertex *v)
{
	t_vector	dir;
	double		tmp;

	tmp = v->z;
	v->z = 0;
	dir = transform_normal(mesh->result, v);
	v->z = tmp;
	return (normalize(dir));
}

t_vertex		normal_sphere(t_mesh *mesh, t_vertex *v)
{
	t_vector	vec;

	vec = transform_normal(mesh->result, v);
	return (normalize(vec));
}

t_vertex		normal_plan(t_mesh *mesh, t_vertex *v)
{
	(void)v;
	return (mesh->prim.plan.normal);
}

t_vertex		normal_parabole(t_mesh *mesh, t_vertex *v)
{
	t_vector	dir;
	double		tmp;

	tmp = v->z;
	v->z = -mesh->prim.cone.coeff;
	dir = transform_normal(mesh->result, v);
	v->z = tmp;
	return (normalize(dir));
}
