/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 12:06:16 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:52:41 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

double		dot_product(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

double		square_length(t_vec *p)
{
	return (p->x * p->x + p->y * p->y + p->z * p->z);
}

double		magnitude(t_vec *p)
{
	return (sqrt(p->x * p->x + p->y * p->y + p->z * p->z));
}

void		normalize(t_vec *p)
{
	double	l;

	l = magnitude(p);
	p->x /= l;
	p->y /= l;
	p->z /= l;
}

double		determinant(double a, double b, double c)
{
	double	d;
	double	d1;
	double	d2;

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
