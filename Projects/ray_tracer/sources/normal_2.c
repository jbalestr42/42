/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:16:07 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:16:08 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_vertex		normal_hyperbole(t_mesh *mesh, t_vertex *v)
{
	t_vector	dir;
	double		tmp;

	tmp = v->z;
	v->z = -mesh->prim.hyperbole.coeff * v->z;
	dir = transform_normal(mesh->result, v);
	v->z = tmp;
	return (normalize(dir));
}

t_vertex		normal_triangle(t_mesh *mesh, t_vertex *v)
{
	(void)v;
	return (mesh->prim.triangle.normal);
}
