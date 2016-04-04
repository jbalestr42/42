#include "scop.h"

const t_matrix IDENTITY_MATRIX = {{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1}};

float				cotangent(float angle)
{
	return ((float)(1.0 / tan(angle)));
}

float				degrees_to_radians(float degrees)
{
	return (degrees * (float)(PI / 180));
}

float				radians_to_degrees(float radians)
{
	return (radians * (float)(180 / PI));
}

t_vector			multiply_matrix_vector(const t_matrix * m, const t_vector * v)
{
	t_vector		out;

	out.v[0] = v->v[0] * m->m[0] + v->v[1] * m->m[4] + v->v[2] * m->m[8];
	out.v[1] = v->v[0] * m->m[1] + v->v[1] * m->m[5] + v->v[2] * m->m[9];
	out.v[2] = v->v[0] * m->m[2] + v->v[1] * m->m[6] + v->v[2] * m->m[10];
	return (out);
}

t_matrix			multiply_matrices(const t_matrix* m1, const t_matrix* m2)
{
	t_matrix		out;
	unsigned int	row;
	unsigned int	column;
	unsigned int	row_offset;

	out = IDENTITY_MATRIX;
	for (row = 0, row_offset = row * 4; row < 4; ++row, row_offset = row * 4)
	{
		for (column = 0; column < 4; ++column)
		{
			out.m[row_offset + column] =
				(m1->m[row_offset + 0] * m2->m[column + 0]) +
				(m1->m[row_offset + 1] * m2->m[column + 4]) +
				(m1->m[row_offset + 2] * m2->m[column + 8]) +
				(m1->m[row_offset + 3] * m2->m[column + 12]);
		}
	}
	return (out);
}

t_matrix			create_projection_matrix(float fovy, float aspect_ratio,
											float near_plane, float far_plane)
{
	t_matrix	out = { { 0 } };
	float		y_scale;
	float		x_scale;
	float		frustum_length;

	y_scale = cotangent(degrees_to_radians(fovy / 2));
	x_scale = y_scale / aspect_ratio;
	frustum_length = far_plane - near_plane;
	out.m[0] = x_scale;
	out.m[5] = y_scale;
	out.m[10] = -((far_plane + near_plane) / frustum_length);
	out.m[11] = -1;
	out.m[14] = -((2 * near_plane * far_plane) / frustum_length);
	return out;
}
