/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:17:48 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/19 14:13:48 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <stdlib.h>
#include "ray_tracer.h"

double			ft_rand(int x)
{
	double		tmp;

	x = (x<<13) ^ x;
	x = (x * (x * x * 15731 + 789221) + 1376312589);
	tmp = 1.0 - (x & 0x7fffffff) / 1073741824.0;
//	tmp = (tmp + 1) / 2; //Rand 0-1
	return (tmp);
}

double			noise_3d(double x, double y, double z)
{
	t_vertex		tmp;

	tmp.x = ft_rand(x) * 850000;
	tmp.y = ft_rand(tmp.x + y) * 850000;
	return (ft_rand(tmp.y + z));
}

double			noise_2d(double x, double y)
{
	t_vertex		tmp;

	tmp.x = ft_rand(x) * 850000;
	return (ft_rand(y + tmp.x));
}

double			cos_interpolate(double a, double b, double t)
{
	double		c;

	c = (1 - cos(t * 3.1415927)) * 0.5;
	return ((1 - c) * a + c * b);
}

void			s_n_integer(t_perlin *p, double x, double y, double z)
{
	if (x >= 0)
		p->integer.x = (int)x;
	else
		p->integer.x = (int)x - 1;
	if (y >= 0)
		p->integer.y = (int)y;
	else
		p->integer.y = (int)y - 1;
	if (z >= 0)
		p->integer.z = (int)z;
	else
		p->integer.z = (int)z - 1;
}
