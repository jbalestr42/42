/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transf_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:18:46 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:18:47 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void	trans_matrix(double ***matrix, double x, double y, double z)
{
	(*matrix)[0][0] = 1.0;
	(*matrix)[0][1] = 0.0;
	(*matrix)[0][2] = 0.0;
	(*matrix)[0][3] = 0.0;
	(*matrix)[1][0] = 0.0;
	(*matrix)[1][1] = 1.0;
	(*matrix)[1][2] = 0.0;
	(*matrix)[1][3] = 0.0;
	(*matrix)[2][0] = 0.0;
	(*matrix)[2][1] = 0.0;
	(*matrix)[2][2] = 1.0;
	(*matrix)[2][3] = 0.0;
	(*matrix)[3][0] = x;
	(*matrix)[3][1] = y;
	(*matrix)[3][2] = z;
	(*matrix)[3][3] = 1.0;
}

void	scale_matrix(double ***matrix, double a, double b, double c)
{
	(*matrix)[0][0] = a;
	(*matrix)[0][1] = 0.0;
	(*matrix)[0][2] = 0.0;
	(*matrix)[0][3] = 0.0;
	(*matrix)[1][0] = 0.0;
	(*matrix)[1][1] = b;
	(*matrix)[1][2] = 0.0;
	(*matrix)[1][3] = 0.0;
	(*matrix)[2][0] = 0.0;
	(*matrix)[2][1] = 0.0;
	(*matrix)[2][2] = c;
	(*matrix)[2][3] = 0.0;
	(*matrix)[3][0] = 0.0;
	(*matrix)[3][1] = 0.0;
	(*matrix)[3][2] = 0.0;
	(*matrix)[3][3] = 1.0;
}

void	rot_matrix_x(double ***matrix, double theta)
{
	(*matrix)[0][0] = 1.0;
	(*matrix)[0][1] = 0.0;
	(*matrix)[0][2] = 0.0;
	(*matrix)[0][3] = 0.0;
	(*matrix)[1][0] = 0.0;
	(*matrix)[1][1] = cos(theta);
	(*matrix)[1][2] = sin(theta);
	(*matrix)[1][3] = 0.0;
	(*matrix)[2][0] = 0.0;
	(*matrix)[2][1] = -sin(theta);
	(*matrix)[2][2] = cos(theta);
	(*matrix)[2][3] = 0.0;
	(*matrix)[3][0] = 0.0;
	(*matrix)[3][1] = 0.0;
	(*matrix)[3][2] = 0.0;
	(*matrix)[3][3] = 1.0;
}

void	rot_matrix_y(double ***matrix, double theta)
{
	(*matrix)[0][0] = cos(theta);
	(*matrix)[0][1] = 0.0;
	(*matrix)[0][2] = -sin(theta);
	(*matrix)[0][3] = 0.0;
	(*matrix)[1][0] = 0.0;
	(*matrix)[1][1] = 1.0;
	(*matrix)[1][2] = 0.0;
	(*matrix)[1][3] = 0.0;
	(*matrix)[2][0] = sin(theta);
	(*matrix)[2][1] = 0.0;
	(*matrix)[2][2] = cos(theta);
	(*matrix)[2][3] = 0.0;
	(*matrix)[3][0] = 0.0;
	(*matrix)[3][1] = 0.0;
	(*matrix)[3][2] = 0.0;
	(*matrix)[3][3] = 1.0;
}

void	rot_matrix_z(double ***matrix, double theta)
{
	(*matrix)[0][0] = cos(theta);
	(*matrix)[0][1] = sin(theta);
	(*matrix)[0][2] = 0.0;
	(*matrix)[0][3] = 0.0;
	(*matrix)[1][0] = -sin(theta);
	(*matrix)[1][1] = cos(theta);
	(*matrix)[1][2] = 0.0;
	(*matrix)[1][3] = 0.0;
	(*matrix)[2][0] = 0.0;
	(*matrix)[2][1] = 0.0;
	(*matrix)[2][2] = 1.0;
	(*matrix)[2][3] = 0.0;
	(*matrix)[3][0] = 0.0;
	(*matrix)[3][1] = 0.0;
	(*matrix)[3][2] = 0.0;
	(*matrix)[3][3] = 1.0;
}
