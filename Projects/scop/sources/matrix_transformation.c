#include "scop.h"

void			scale_matrix(t_matrix* m, float x, float y, float z)
{
	t_matrix	scale;

	scale = IDENTITY_MATRIX;
	scale.m[0] = x;
	scale.m[5] = y;
	scale.m[10] = z;
	t_matrix tmp = multiply_matrices(m, &scale);
	memcpy(m->m, tmp.m, sizeof(m->m));
}

void			translate_matrix(t_matrix* m, t_vector *v)
{
	t_matrix	translation;

	translation = IDENTITY_MATRIX;
	translation.m[12] = v->v[0];
	translation.m[13] = v->v[1];
	translation.m[14] = v->v[2];
	t_matrix tmp = multiply_matrices(m, &translation);
	memcpy(m->m, tmp.m, sizeof(m->m));
}

void			rotate_about_x(t_matrix* m, float angle)
{
	t_matrix	rotation;
	float		sine;
	float		cosine;

	rotation = IDENTITY_MATRIX;
	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation.m[5] = cosine;
	rotation.m[6] = -sine;
	rotation.m[9] = sine;
	rotation.m[10] = cosine;
	t_matrix tmp = multiply_matrices(m, &rotation);
	memcpy(m->m, tmp.m, sizeof(m->m));
}

void			rotate_about_y(t_matrix* m, float angle)
{
	t_matrix	rotation;
	float		sine;
	float		cosine;

	rotation = IDENTITY_MATRIX;
	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation.m[0] = cosine;
	rotation.m[8] = sine;
	rotation.m[2] = -sine;
	rotation.m[10] = cosine;
	t_matrix tmp = multiply_matrices(m, &rotation);
	memcpy(m->m, tmp.m, sizeof(m->m));
}

void			rotate_about_z(t_matrix* m, float angle)
{
	t_matrix	rotation;
	float		sine;
	float		cosine;

	rotation = IDENTITY_MATRIX;
	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation.m[0] = cosine;
	rotation.m[1] = -sine;
	rotation.m[4] = sine;
	rotation.m[5] = cosine;
	t_matrix tmp = multiply_matrices(m, &rotation);
	memcpy(m->m, tmp.m, sizeof(m->m));
}
