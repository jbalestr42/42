/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:31:35 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 05:19:01 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

/*
** Scalar product : u.v
*/
double			dot(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double			square_length(t_vector u)
{
	return (u.x * u.x + u.y * u.y + u.z * u.z);
}

double			magnitude(t_vector u)
{
	return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}

t_vector		normalize(t_vector u)
{
	double		l;

	l = magnitude(u);
	u.x /= l;
	u.y /= l;
	u.z /= l;
	return (u);
}

double			determinant(double a, double b, double c)
{
	double		d;
	double		d1;
	double		d2;

	d = pow(b, 2) - (4 * a * c);
	if (d < 0)
		return (0);
	if (d == 0)
		return (-c / b);
	d = sqrt(d);
	d1 = ((-b) + d) / (2 * a);
	d2 = ((-b) - d) / (2 * a);
	if (d1 < d2)
		return (d1);
	return (d2);
}
