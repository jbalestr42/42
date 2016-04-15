/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:18:04 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 15:25:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			scale_matrix(t_matrix *m, float x, float y, float z)
{
	t_matrix	scale;
	t_matrix	tmp;

	identity(&scale);
	scale.m[0] = x;
	scale.m[5] = y;
	scale.m[10] = z;
	tmp = multiply_matrices(m, &scale);
	memcpy(m->m, tmp.m, sizeof(m->m));
}

void			translate_matrix(t_matrix *m, t_vector *v)
{
	t_matrix	translation;
	t_matrix	tmp;

	identity(&translation);
	translation.m[12] = v->v[0];
	translation.m[13] = v->v[1];
	translation.m[14] = v->v[2];
	tmp = multiply_matrices(m, &translation);
	memcpy(m->m, tmp.m, sizeof(m->m));
}

void			rotate_about_x(t_matrix *m, float angle)
{
	t_matrix	rotation;
	t_matrix	tmp;
	float		sine;
	float		cosine;

	identity(&rotation);
	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation.m[5] = cosine;
	rotation.m[6] = -sine;
	rotation.m[9] = sine;
	rotation.m[10] = cosine;
	tmp = multiply_matrices(m, &rotation);
	memcpy(m->m, tmp.m, sizeof(m->m));
}

void			rotate_about_y(t_matrix *m, float angle)
{
	t_matrix	rotation;
	t_matrix	tmp;
	float		sine;
	float		cosine;

	identity(&rotation);
	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation.m[0] = cosine;
	rotation.m[8] = sine;
	rotation.m[2] = -sine;
	rotation.m[10] = cosine;
	tmp = multiply_matrices(m, &rotation);
	memcpy(m->m, tmp.m, sizeof(m->m));
}

void			rotate_about_z(t_matrix *m, float angle)
{
	t_matrix	rotation;
	t_matrix	tmp;
	float		sine;
	float		cosine;

	identity(&rotation);
	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation.m[0] = cosine;
	rotation.m[1] = -sine;
	rotation.m[4] = sine;
	rotation.m[5] = cosine;
	tmp = multiply_matrices(m, &rotation);
	memcpy(m->m, tmp.m, sizeof(m->m));
}
