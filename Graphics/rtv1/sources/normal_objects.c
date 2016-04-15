/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 12:03:17 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 12:31:05 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_vec			normal_cone(t_cone *con, t_vec *vi)
{
	t_vec		n;
	t_vec		tmp;

	tmp.x = vi->x;
	tmp.y = vi->y;
	tmp.z = con->pos.z;
	sub_vec(&n, &tmp, &con->pos);
	mul_vec_val(&n, &n, con->coeff);
	return (n);
}

t_vec			normal_cylinder(t_cylinder *cyl, t_vec *vi)
{
	t_vec		n;
	t_vec		tmp;

	tmp.x = vi->x;
	tmp.y = vi->y;
	tmp.z = cyl->pos.z;
	sub_vec(&n, &tmp, &cyl->pos);
	mul_vec_val(&n, &n, cyl->radius);
	return (n);
}

t_vec			normal_sphere(t_sphere *sph, t_vec *vi)
{
	t_vec		n;

	sub_vec(&n, vi, &sph->center);
	mul_vec_val(&n, &n, sph->radius);
	return (n);
}
