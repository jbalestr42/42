/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:57:00 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 05:18:39 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_vertex		transform_pos(double **m, t_vertex *p)
{
	t_vertex	cpy;

	cpy.x = m[0][0] * p->x + m[1][0] * p->y + m[2][0] * p->z + m[3][0];
	cpy.y = m[0][1] * p->x + m[1][1] * p->y + m[2][1] * p->z + m[3][1];
	cpy.z = m[0][2] * p->x + m[1][2] * p->y + m[2][2] * p->z + m[3][2];
	return (cpy);
}

t_vector		transform_dir(double **m, t_vector *p)
{
	t_vector	cpy;

	cpy.x = m[0][0] * p->x + m[1][0] * p->y + m[2][0] * p->z;
	cpy.y = m[0][1] * p->x + m[1][1] * p->y + m[2][1] * p->z;
	cpy.z = m[0][2] * p->x + m[1][2] * p->y + m[2][2] * p->z;
	return (cpy);
}

t_vertex		transform_normal(double **m, t_vertex *p)
{
	t_vertex	cpy;

	cpy.x = m[0][0] * p->x + m[0][1] * p->y + m[0][2] * p->z;
	cpy.y = m[1][0] * p->x + m[1][1] * p->y + m[1][2] * p->z;
	cpy.z = m[2][0] * p->x + m[2][1] * p->y + m[2][2] * p->z;
	return (cpy);
}

void			transform_matrix(double **matrix1, double **matrix2)
{
	double		**cpy;

	cpy = malloc_matrix(4, 4);
	matrix_multiply(matrix1, matrix2, cpy);
	copy_matrix(matrix1, cpy);
	free_matrix(cpy, 4);
}

void			compute_matrix(t_mesh *mesh)
{
	mesh->result = id_matrix();
	transform_matrix(mesh->result, mesh->scale);
	transform_matrix(mesh->result, mesh->rot_x);
	transform_matrix(mesh->result, mesh->rot_y);
	transform_matrix(mesh->result, mesh->rot_z);
	transform_matrix(mesh->result, mesh->trans);
}
