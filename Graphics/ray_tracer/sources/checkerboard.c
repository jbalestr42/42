/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:09:18 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:09:20 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

t_color			checker1(t_vertex p, t_color pix1, t_color pix2, int n)
{
	t_color		tmp;
	int			x;
	int			y;

	x = (p.x > 0) ? ((int)fabs(p.x)) % (n * 2) : ((int)fabs(p.x - n)) % (n * 2);
	y = (p.y > 0) ? ((int)fabs(p.y)) % (n * 2) : ((int)fabs(p.y)) % (n * 2);
	if (((x < n) && (y < n)) || (!(x < n) && !(y < n)))
	{
		tmp.r = pix1.r;
		tmp.g = pix1.g;
		tmp.b = pix1.b;
	}
	else
	{
		tmp.r = pix2.r;
		tmp.g = pix2.g;
		tmp.b = pix2.b;
	}
	return (tmp);
}

t_color			checker2(t_vertex p, t_color pix1, t_color pix2, int n)
{
	t_color		tmp;
	int			x;
	int			z;

	x = (p.x > 0) ? ((int)fabs(p.x)) % (n * 2) : ((int)fabs(p.x - n)) % (n * 2);
	z = (p.z > 0) ? ((int)fabs(p.z)) % (n * 2) : ((int)fabs(p.z - n)) % (n * 2);
	if (((x < n) && (z < n)) || (!(x < n) && !(z < n)))
	{
		tmp.r = pix1.r;
		tmp.g = pix1.g;
		tmp.b = pix1.b;
	}
	else
	{
		tmp.r = pix2.r;
		tmp.g = pix2.g;
		tmp.b = pix2.b;
	}
	return (tmp);
}

t_color			checker3(t_vertex p, t_color pix1, t_color pix2, int n)
{
	t_color		tmp;
	int			x;
	int			y;
	int			z;

	x = (p.x > 0) ? ((int)fabs(p.x)) % (n * 2) : ((int)fabs(p.x - n)) % (n * 2);
	y = (p.y > 0) ? ((int)fabs(p.y)) % (n * 2) : ((int)fabs(p.y)) % (n * 2);
	z = (p.z > 0) ? ((int)fabs(p.z)) % (n * 2) : ((int)fabs(p.z - n)) % (n * 2);
	if (((x < n) && (y < n) && (z < n)) || (!(x < n) && !(y < n) && !(z < n)))
	{
		tmp.r = pix1.r;
		tmp.g = pix1.g;
		tmp.b = pix1.b;
	}
	else
	{
		tmp.r = pix2.r;
		tmp.g = pix2.g;
		tmp.b = pix2.b;
	}
	return (tmp);
}

t_color			no_mat(t_vertex p, t_color pix1, t_color pix2, int n)
{
	(void)p;
	(void)pix1;
	(void)pix2;
	(void)n;
	return (pix1);
}
