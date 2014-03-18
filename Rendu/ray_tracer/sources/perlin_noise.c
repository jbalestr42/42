/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:17:59 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/14 17:27:33 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "perlin.h"

#include <stdio.h>

double			smooth_noise(double x, double y, double z)
{
	t_perlin	p;

	s_n_integer(&p, x, y, z);
	p.doubler.x = x - p.integer.x;
	p.doubler.y = y - p.integer.y;
	p.doubler.z = z - p.integer.z;
	p.a.y = noise_3d(p.integer.x, p.integer.y, p.integer.z);
	p.a.z = noise_3d(p.integer.x + 1, p.integer.y, p.integer.z);
	p.b.y = noise_3d(p.integer.x, p.integer.y + 1, p.integer.z);
	p.b.z = noise_3d(p.integer.x + 1, p.integer.y + 1, p.integer.z);
	p.c.y = noise_3d(p.integer.x, p.integer.y, p.integer.z + 1);
	p.c.z = noise_3d(p.integer.x + 1, p.integer.y, p.integer.z + 1);
	p.d.y = noise_3d(p.integer.x, p.integer.y + 1, p.integer.z + 1);
	p.d.z = noise_3d(p.integer.x + 1, p.integer.y + 1, p.integer.z + 1);
	p.a.x = cos_interpolate(p.a.y, p.a.z, p.doubler.x);
	p.b.x = cos_interpolate(p.b.y, p.b.z, p.doubler.x);
	p.c.x = cos_interpolate(p.c.y, p.c.z, p.doubler.x);
	p.d.x = cos_interpolate(p.d.y, p.d.z, p.doubler.x);
	p.v = cos_interpolate(p.a.x, p.b.x, p.doubler.y);
	p.w = cos_interpolate(p.b.x, p.c.x, p.doubler.y);
	return (cos_interpolate(p.v, p.w, p.doubler.z));
}

double			ft_perlin(t_env *e, double x, double y, double z)
{
	double		result;
	double		f;
	double		amplitude;
	int			i;
	int			t;

	(void)e;
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
//	printf("%f\n", result);
	return (result);
}

t_color			ft_more_effect(t_env *e, double x, double y, double z)
{
	double		result;
	t_color		col;
	int			i;

	i = 0;
	result = 0;
	while (++i < 15)
	{
			result += (1 / i) * ft_perlin(e, i * x, i * y, i * z);
	}
	result = cos(((x * y * z) / (x)) + result);
	//		e->color.x *= 1 - result;
	//		e->color.y *= result;
	//		e->color.z *= 1 - result;
	//	esult *= ft_perlin(e, x, y, z);
	col.r = result;
	col.g = result;
	col.b = result;
	return (col);
}

t_color			marble(t_env *e, double x, double y, double z)
{
	t_color		col;
	double		value;
	t_vertex		c1;
	t_vertex		c2;
	double		result;
	int			i;

	i = 0;
	result = 0;
	while (++i < 10)
	{
		result += (1 / i) * ft_perlin(e, i * x, i * y, i * z);
	}
	value = sqrt(fabs(sin(2 * 3.141592 * result)));
	c1 = init_vec(0.5, 0.5, 0.5);
	c2 = init_vec(0.9, 0.9, 0.9);
	col.r = c1.x * (1 - value) + c2.x * value;
	col.g = c1.y * (1 - value) + c2.y * value;
	col.b = c1.z * (1 - value) + c2.z * value;
	return (col);
}

t_color			wood(t_env *e, double x, double y, double z)
{
	t_color		col;
	double		step;
	t_vertex	c1;
	t_vertex	c2;
	double		value;
	double		f;

//	double		result;
//	int			i;


//		i = 0;
//		result = 0;
//		while (++i < 10)
//		{
//			result += (1 / i) * ft_perlin(e, i * x, i * y, i * z);
//		}

	step = 0.2;
	c1 = init_vec(0.05, 0.05, 0.05);
	c2 = init_vec(0.05, 0.1, 0.1);
	value = fmod(ft_perlin(e, x, y, z), step);
	if (value > step / 2)
			value = step - value;
	f = (1 - cos(M_PI * value / (step / 2))) / 2;
	col.r = c1.x * (1 - f) + c2.x * f;
	col.g = c1.y * (1 - f) + c2.y * f;
	col.b = c1.z * (1 - f) + c2.z * f;
	return (col);
}
/*
void obtenirPixel(t_env *e, double x, double y, double z) {

	(void)y;
	(void)z;
    double value = sqrt(fabs(sin(2 * 3.141592 * x)));
//	double value = x;

//    t_vertex resultat;
//    if(value > s1 / 2)
//        value = s1 - value;
	else if(value < s2) {
	      double f = (value - s1) / (s2 - s1);
        resultat.x = c1.x * (1 - f) + c2.x * f;
        resultat.y = c1.y * (1 - f) + c2.y * f;
	       resultat.z = c1.z * (1 - f) + c2.z * f;
    } else if(value < s3) {
        double f = (value - s2) / (s3 - s2);
        resultat.x = c2.x * (1 - f) + c3.x * f;
        resultat.y = c2.y * (1 - f) + c3.y * f;
        resultat.z = c2.z * (1 - f) + c3.z * f;
    } else resultat = c3;

	e->color.x = resultat.x;
	e->color.y = resultat.y;
	e->color.z = resultat.z;
	double f = (1 - cos(M_PI * value / (s1 / 2))) / 2;
	e->color.x = c1.x * (1 - value) + c2.x * value;
	e->color.y = c1.y * (1 - value) + c2.y * value;
	e->color.z = c1.z * (1 - value) + c2.z * value;
}*/
