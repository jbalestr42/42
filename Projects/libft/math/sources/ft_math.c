/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:13:09 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/05 20:50:51 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static double	ft_degree_to_radian(double degree)
{
	while (degree > 360)
		degree -= 360;
	while (degree < -360)
		degree += 360;
	return (degree * PI / 180);
}

static double	ft_sin_rad(double x)
{
	double	sin;

	if (x < -3.14159265)
		x += 6.28318531;
	else
	{
		if (x > 3.14159265)
			x -= 6.28318531;
	}
	if (x < 0)
		sin = 1.27323954 * x + 0.405284735 * x * x;
	else
		sin = 1.27323954 * x - 0.405284735 * x * x;
	if (x < 0)
	{
		sin = 1.27323954 * x + 0.405284735 * x * x;
		if (sin < 0)
			sin = 0.225 * (sin * -sin - sin) + sin;
		else
			sin = 0.225 * (sin * sin - sin) + sin;
	}
	else
	{
		sin = 1.27323954 * x - 0.405284735 * x * x;
		if (sin < 0)
			sin = 0.225 * (sin * -sin - sin) + sin;
		else
			sin = 0.225 * (sin * sin - sin) + sin;
	}
	return (sin);
}

double			ft_sin(double angle)
{
	return (ft_sin_rad(ft_degree_to_radian(angle)));
}

/*
** compute cosine: sin(x + PI/2) = cos(x)
*/
double			ft_cos(double angle)
{
	double	x;

	x = ft_degree_to_radian(angle);
	x += 1.57079632;
	return (ft_sin_rad(x));
}

double			ft_tan(double angle)
{
	if (angle == 90)
		return (2000000000);
	return (ft_sin(angle) / ft_cos(angle));
}
