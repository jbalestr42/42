/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_effect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:17:59 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/27 20:08:09 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "perlin.h"

t_color			perlin_zebra(t_vertex var, t_color pix1, t_color pix2, int n)
{
	double		result;
	t_color		col;

	(void)pix2;
	(void)n;
	result = ft_perlin(var.x, var.y, var.z);
	result = cos(((var.x * var.y * var.z) / (var.x * 2)) + result);
	col.r = pix1.r * result;
	col.g = pix1.g * result;
	col.b = pix1.b * result;
	return (col);
}

t_color			perlin_marble(t_vertex var, t_color pix1, t_color pix2, int n)
{
	t_p_effect	e;

	(void)pix1;
	(void)pix2;
	(void)n;
	e.result = ft_perlin(var.x, var.y, var.z);
	e.value = sqrt(fabs(sin(2 * 3.141592 * e.result)));
	e.c1 = init_vec(0.5, 0.5, 0.5);
	e.c2 = init_vec(0.9, 0.9, 0.9);
	e.color.r = e.c1.x * (1 - e.value) + e.c2.x * e.value;
	e.color.g = e.c1.y * (1 - e.value) + e.c2.y * e.value;
	e.color.b = e.c1.z * (1 - e.value) + e.c2.z * e.value;
	return (e.color);
}

t_color			perlin_wood(t_vertex var, t_color pix1, t_color pix2, int n)
{
	t_p_effect	e;
	double		step;
	double		f;

	(void)pix1;
	(void)pix2;
	(void)n;
	e.result = ft_perlin(var.x, var.y, var.z);
	step = 0.2;
	e.c1 = init_vec(0.0, 0.2, 0.4);
	e.c2 = init_vec(0.0, 0.0, 0.2);
	e.value = fmod(ft_perlin(var.x, var.y, var.z), step);
	if (e.value > step / 2)
		e.value = step - e.value;
	f = (1 - cos(M_PI * e.value / (step / 2))) / 2;
	e.color.r = e.c1.x * (1 - f) + e.c2.x * f;
	e.color.g = e.c1.y * (1 - f) + e.c2.y * f;
	e.color.b = e.c1.z * (1 - f) + e.c2.z * f;
	return (e.color);
}

double			perlin_ocean(t_env *e, t_vertex pos, int type, int light)
{
	double		coef;
	double		var;

	coef = 0;
	if (e->ocean && type == T_PLAN)
	{
		if (light == DIF)
		{
			var = (pos.x * pos.y * pos.z) / 5;
			coef = cos(var + ft_perlin(pos.x, pos.y, pos.z)) * 700;
		}
		else if (light == SPE)
		{
			var = pos.z / 3;
			coef = cos(var + ft_perlin(pos.x, pos.y, pos.z)) * 100;
		}
		else if (light == INTER)
		{
			var = pos.z / 3;
			coef = cos(var + ft_perlin(pos.x, pos.y, pos.z)) * 7;
		}
	}
	return (coef);
}
