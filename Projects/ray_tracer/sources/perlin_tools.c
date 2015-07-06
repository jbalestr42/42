/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:17:48 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/27 11:42:26 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ray_tracer.h"

static double	ft_rand(int x)
{
	double		tmp;

	x = (x << 13) ^ x;
	x = (x * (x * x * 15731 + 789221) + 1376312589);
	tmp = 1.0 - (x & 0x7fffffff) / 1073741824.0;
	return (tmp);
}

double			noise_3d(double x, double y, double z)
{
	t_vertex	tmp;

	tmp.x = ft_rand(x) * 850000;
	tmp.y = ft_rand(tmp.x + y) * 850000;
	return (ft_rand(tmp.y + z));
}

double			cos_interpolate(double a, double b, double t)
{
	double		c;

	c = (1 - cos(t * 3.1415927)) * 0.5;
	return ((1 - c) * a + c * b);
}
