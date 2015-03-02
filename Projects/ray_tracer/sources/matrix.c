/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:03:37 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 11:39:15 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"

double		**malloc_matrix(int x, int y)
{
	int		i;
	int		j;
	double	**t;

	if (!(t = (double **)malloc(sizeof(double *) * x)))
		return (NULL);
	i = -1;
	while (++i < x)
	{
		if (!(t[i] = (double *)malloc(sizeof(double) * y)))
			return (NULL);
		j = -1;
		while (++j < y)
			t[i][j] = 0.0;
	}
	return (t);
}

void		free_matrix(double **matrix, int size)
{
	int		i;

	i = -1;
	if (!matrix)
		return ;
	while (++i < size)
		free(matrix[i]);
	free(matrix);
}

int			matrix_multiply(double **matrix1, double **matrix2, double **res)
{
	int		sum;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			sum = 0;
			while (++k < 4)
				sum += matrix1[i][k] * matrix2[k][j];
			res[i][j] = sum;
		}
	}
	return (1);
}

void		copy_matrix(double **matrix1, double **matrix2)
{
	matrix1[0][0] = matrix2[0][0];
	matrix1[0][1] = matrix2[0][1];
	matrix1[0][2] = matrix2[0][2];
	matrix1[0][3] = matrix2[0][3];
	matrix1[1][0] = matrix2[1][0];
	matrix1[1][1] = matrix2[1][1];
	matrix1[1][2] = matrix2[1][2];
	matrix1[1][3] = matrix2[1][3];
	matrix1[2][0] = matrix2[2][0];
	matrix1[2][1] = matrix2[2][1];
	matrix1[2][2] = matrix2[2][2];
	matrix1[2][3] = matrix2[2][3];
	matrix1[3][0] = matrix2[3][0];
	matrix1[3][1] = matrix2[3][1];
	matrix1[3][2] = matrix2[3][2];
	matrix1[3][3] = matrix2[3][3];
}

double		**id_matrix(void)
{
	double	**m;
	int		i;
	int		j;

	m = malloc_matrix(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m[i][j] = 0.0;
	}
	m[0][0] = 1.0;
	m[1][1] = 1.0;
	m[2][2] = 1.0;
	m[3][3] = 1.0;
	return (m);
}
