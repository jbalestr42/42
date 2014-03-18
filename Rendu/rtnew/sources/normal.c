/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:34:43 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/13 13:07:46 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

/*
 * dans la position simple de l'objet, la normal est v,
 * dans les coordonnees complexes de l'objet, la normal est v * result
 * v = intersection en coordonnees complexe de l'objet
 */
// la normal du cylindre est fausse

t_vertex		normal_cone(t_mesh *mesh, t_vertex *v)
{
	t_vector	pos;

	pos.x = -mesh->trans[3][0];
	pos.y = -mesh->trans[3][1];
	pos.z = v->z;
	return (normalize(sub(*v, pos)));
}

t_vertex		normal_cylinder(t_mesh *mesh, t_vertex *v)
{
	t_vector	pos;

	pos.x = -mesh->trans[3][0];
	pos.y = -mesh->trans[3][1];
	pos.z = v->z;
	return (normalize(sub(*v, pos)));
}

t_vertex		normal_sphere(t_mesh *mesh, t_vertex *v)
{
	t_vector	pos;

	pos.x = -mesh->trans[3][0];
	pos.y = -mesh->trans[3][1];
	pos.z = -mesh->trans[3][2];
	return (normalize(sub(*v, pos)));
}

t_vertex		normal_plan(t_mesh *mesh, t_vertex *v)
{
	(void)v;
	return (mesh->prim.plan.normal);
}
