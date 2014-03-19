/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:17:59 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/19 18:02:23 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "perlin.h"

double			smooth_noise(double x, double y, double z)
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

t_color			perlin_zebra(double x, double y, double z, t_color pix)
{
	double		result;
	t_color		col;

	result = ft_perlin(x, y, z);
	result = cos(((x * y * z) / (x / 3)) + result);
	col.r = pix.r * result;
	col.g = pix.g * result;
	col.b = pix.b * result;
	return (col);
}

t_color			perlin_marble(double x, double y, double z)
{
	t_effect	e;

	e.result = ft_perlin(x, y, z);
	e.value = sqrt(fabs(sin(2 * 3.141592 * e.result)));
	e.c1 = init_vec(0.5, 0.5, 0.5);
	e.c2 = init_vec(0.9, 0.9, 0.9);
	e.color.r = e.c1.x * (1 - e.value) + e.c2.x * e.value;
	e.color.g = e.c1.y * (1 - e.value) + e.c2.y * e.value;
	e.color.b = e.c1.z * (1 - e.value) + e.c2.z * e.value;
	return (e.color);
}

t_color			perlin_wood(double x, double y, double z)
{
	t_effect	e;
	double		step;
	double		f;

	e.result = ft_perlin(x, y, z);
	step = 0.2;
	e.c1 = init_vec(0.0, 0.2, 0.4);
	e.c2 = init_vec(0.0, 0.0, 0.2);
	e.value = fmod(ft_perlin(x, y, z), step);
	if (e.value > step / 2)
			e.value = step - e.value;
	f = (1 - cos(M_PI * e.value / (step / 2))) / 2;
	e.color.r = e.c1.x * (1 - f) + e.c2.x * f;
	e.color.g = e.c1.y * (1 - f) + e.c2.y * f;
	e.color.b = e.c1.z * (1 - f) + e.c2.z * f;
	return (e.color);
}
