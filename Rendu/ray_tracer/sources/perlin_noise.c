/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:17:59 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/27 05:17:01 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "perlin.h"

static void		s_n_integer(t_perlin *p, double x, double y, double z)
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

static double	smooth_noise(double x, double y, double z)
{
	t_perlin	p;

	s_n_integer(&p, x, y, z);
	p.fract.x = x - p.integer.x;
	p.fract.y = y - p.integer.y;
	p.fract.z = z - p.integer.z;
	p.a.y = noise_3d(p.integer.x, p.integer.y, p.integer.z);
	p.a.z = noise_3d(p.integer.x + 1, p.integer.y, p.integer.z);
	p.b.y = noise_3d(p.integer.x, p.integer.y + 1, p.integer.z);
	p.b.z = noise_3d(p.integer.x + 1, p.integer.y + 1, p.integer.z);
	p.c.y = noise_3d(p.integer.x, p.integer.y, p.integer.z + 1);
	p.c.z = noise_3d(p.integer.x + 1, p.integer.y, p.integer.z + 1);
	p.d.y = noise_3d(p.integer.x, p.integer.y + 1, p.integer.z + 1);
	p.d.z = noise_3d(p.integer.x + 1, p.integer.y + 1, p.integer.z + 1);
	p.a.x = cos_interpolate(p.a.y, p.a.z, p.fract.x);
	p.b.x = cos_interpolate(p.b.y, p.b.z, p.fract.x);
	p.c.x = cos_interpolate(p.c.y, p.c.z, p.fract.x);
	p.d.x = cos_interpolate(p.d.y, p.d.z, p.fract.x);
	p.v = cos_interpolate(p.a.x, p.b.x, p.fract.y);
	p.w = cos_interpolate(p.c.x, p.d.x, p.fract.y);
	return (cos_interpolate(p.v, p.w, p.fract.z));
}

double			ft_perlin(double x, double y, double z)
{
	double		result;
	double		f;
	double		amplitude;
	int			i;
	int			t;

	result = 0;
	f = FREQUENCY;
	amplitude = 1;
	i = -1;
	while (++i < OCTAVES)
	{
		t = i * 4096;
		result += smooth_noise(x * f + t, y * f + t, z * f + t) * amplitude;
		amplitude *= PERSISTANCE;
		f *= 2;
	}
	result *= (1 - PERSISTANCE) / (1 - amplitude);
	return (result);
}
