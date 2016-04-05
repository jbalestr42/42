/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:18:06 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:48:57 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector			multiply_matrix_vector(const t_matrix *m, const t_vector *v)
{
	t_vector		out;

	out.v[0] = v->v[0] * m->m[0] + v->v[1] * m->m[4] + v->v[2] * m->m[8];
	out.v[1] = v->v[0] * m->m[1] + v->v[1] * m->m[5] + v->v[2] * m->m[9];
	out.v[2] = v->v[0] * m->m[2] + v->v[1] * m->m[6] + v->v[2] * m->m[10];
	return (out);
}

t_matrix			multiply_matrices(const t_matrix *m1, const t_matrix *m2)
{
	t_matrix		out;
	unsigned int	row;
	unsigned int	column;
	unsigned int	row_offset;

	identity(&out);
	row = 0;
	row_offset = row * 4;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			out.m[row_offset + column] =
				(m1->m[row_offset + 0] * m2->m[column + 0]) +
				(m1->m[row_offset + 1] * m2->m[column + 4]) +
				(m1->m[row_offset + 2] * m2->m[column + 8]) +
				(m1->m[row_offset + 3] * m2->m[column + 12]);
			++column;
		}
		++row;
		row_offset = row * 4;
	}
	return (out);
}

t_matrix			create_projection_matrix(float fovy, float aspect_ratio,
											float near_plane, float far_plane)
{
	t_matrix		out;
	float			y_scale;
	float			x_scale;
	float			frustum_length;

	init_matrix(&out);
	y_scale = cotangent(degrees_to_radians(fovy / 2));
	x_scale = y_scale / aspect_ratio;
	frustum_length = far_plane - near_plane;
	out.m[0] = x_scale;
	out.m[5] = y_scale;
	out.m[10] = -((far_plane + near_plane) / frustum_length);
	out.m[11] = -1;
	out.m[14] = -((2 * near_plane * far_plane) / frustum_length);
	return (out);
}

void				init_vector(t_vector *v, float x, float y, float z)
{
	v->v[0] = x;
	v->v[1] = y;
	v->v[2] = z;
}
