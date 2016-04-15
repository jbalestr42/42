/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:51:18 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 15:23:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float		cotangent(float angle)
{
	return ((float)(1.0 / tan(angle)));
}

float		degrees_to_radians(float degrees)
{
	return (degrees * (float)(PI / 180));
}

float		radians_to_degrees(float radians)
{
	return (radians * (float)(180 / PI));
}

void		identity(t_matrix *matrix)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		matrix->m[i] = 0;
		i++;
	}
	matrix->m[0] = 1.f;
	matrix->m[5] = 1.f;
	matrix->m[10] = 1.f;
	matrix->m[15] = 1.f;
}

void		init_matrix(t_matrix *matrix)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		matrix->m[i] = 0;
		i++;
	}
}
