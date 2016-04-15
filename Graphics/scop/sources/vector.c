/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:46:44 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:48:56 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float	magnitude(t_vector *vector)
{
	return (sqrt(vector->v[0] * vector->v[0] + vector->v[1]
				* vector->v[1] + vector->v[2] * vector->v[2]));
}

void	normalize(t_vector *vector)
{
	float mag;

	mag = magnitude(vector);
	vector->v[0] /= mag;
	vector->v[1] /= mag;
	vector->v[2] /= mag;
}

void	cross_product(t_vector *res, t_vector *v1, t_vector *v2)
{
	res->v[0] = v1->v[1] * v2->v[2] - v1->v[2] * v2->v[1];
	res->v[1] = v1->v[2] * v2->v[0] - v1->v[0] * v2->v[2];
	res->v[2] = v1->v[0] * v2->v[1] - v1->v[1] * v2->v[0];
}

float	dot(t_vector *v1, t_vector *v2)
{
	return (v1->v[0] * v2->v[0] + v1->v[1] * v2->v[1] + v1->v[2] * v2->v[2]);
}

void	add_vector(t_vector *res, t_vector *v1, t_vector *v2, float factor)
{
	res->v[0] = v1->v[0] + (v2->v[0] * factor);
	res->v[1] = v1->v[1] + (v2->v[1] * factor);
	res->v[2] = v1->v[2] + (v2->v[2] * factor);
}
