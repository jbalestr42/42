/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:08:44 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:08:46 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

static void		compute_pix(t_env *e, t_color *col, double dx, double dy)
{
	t_color		tmp;
	t_compute	c;

	compute_ray(e, e->aa.ray, dx, dy);
	if (intersect_mesh(e, e->aa.ray, e->aa.mesh, e->aa.inter))
	{
		c = init_compute(*e->aa.ray, *e->aa.mesh, *e->aa.inter, *e->aa.ray);
		tmp = compute_color(e, c, 0, 1.0);
		col->r += tmp.r * 0.9;
		col->g += tmp.g * 0.9;
		col->b += tmp.b * 0.9;
	}
}

t_color			compute_aa(t_env *e, t_ray *ray, t_mesh **mesh, t_vertex *inter)
{
	t_color		col;
	double		d[2];
	t_compute	c;

	e->aa.ray = ray;
	e->aa.mesh = mesh;
	e->aa.inter = inter;
	d[0] = e->aa.dx;
	d[1] = e->aa.dy;
	c = init_compute(*ray, *mesh, *inter, *ray);
	col = compute_color(e, c, 0, 1.0);
	compute_pix(e, &col, e->aa.x + d[0], e->aa.y);
	compute_pix(e, &col, e->aa.x + 2 * d[0], e->aa.y);
	compute_pix(e, &col, e->aa.x, e->aa.y + d[1]);
	compute_pix(e, &col, e->aa.x, e->aa.y + 2 * d[1]);
	compute_pix(e, &col, e->aa.x - d[0], e->aa.y);
	compute_pix(e, &col, e->aa.x - 2 * d[0], e->aa.y);
	compute_pix(e, &col, e->aa.x, e->aa.y - d[1]);
	compute_pix(e, &col, e->aa.x, e->aa.y - 2 * d[1]);
	compute_pix(e, &col, e->aa.x + d[0], e->aa.y + d[1]);
	compute_pix(e, &col, e->aa.x - d[0], e->aa.y - d[1]);
	compute_pix(e, &col, e->aa.x + d[0], e->aa.y - d[1]);
	compute_pix(e, &col, e->aa.x - d[0], e->aa.y + d[1]);
	col = prod_col_val(col, (1.0 / 13.0));
	return (col);
}
