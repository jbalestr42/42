/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:57:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 12:05:40 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray_tracer.h"

double			inter_sphere(t_object *obj, t_ray *ray)
{
	t_sphere	*sphere;
	t_vec		tmp;
	double		d;
	double		a;
	double		b;
	double		c;

	sphere = &obj->prim.sphere;
	a = square_length(&ray->dir);
	sub_vec(&tmp, &ray->ori, &sphere->center);
	b = 2 * dot_product(&ray->dir, &tmp);
	c = square_length(&sphere->center) + square_length(&ray->ori)
		+ -2 * dot_product(&sphere->center, &ray->ori)
		- pow(sphere->radius, 2);
	d = determinant(a, b, c);
	if (d >= 0)
		return (d);
	return (-1);
}

double			inter_plan(t_object *obj, t_ray *ray)
{
	t_plan		*plan;
	t_vec		tmp;
	double		d;

	plan = &obj->prim.plan;
	sub_vec(&tmp, &ray->ori, &plan->pos);
	d = -(dot_product(&plan->normal, &tmp)
		/ dot_product(&plan->normal, &ray->dir));
	return (d);
}

double			inter_cylinder(t_object *obj, t_ray *ray)
{
	t_cylinder	*cyl;
	t_vec		tmp;
	double		d;
	double		a;
	double		b;
	double		c;

	cyl = &obj->prim.cylinder;
	sub_vec(&tmp, &ray->ori, &cyl->pos);
	a = pow(ray->dir.x, 2) + pow(ray->dir.y, 2);
	b = 2 * (ray->dir.x * tmp.x + ray->dir.y * tmp.y);
	c = pow(ray->ori.x, 2) + pow(ray->ori.y, 2) - pow(cyl->radius, 2);
	d = determinant(a, b, c);
	return (d);
}

double			inter_cone(t_object *obj, t_ray *ray)
{
	t_cone		*con;
	double		d;
	double		a;
	double		b;
	double		c;

	con = &obj->prim.cone;
	a = pow(ray->dir.x, 2) + pow(ray->dir.y, 2)
		- pow(ray->dir.z, 2) * pow(tan(con->coeff), 2);
	b = (2 * (ray->dir.x * ray->ori.x + ray->dir.y * ray->ori.y))
		- (2 * ray->dir.z * ray->ori.z * pow(tan(con->coeff), 2));
	c = pow(ray->ori.x, 2) + pow(ray->ori.y, 2)
	- (pow(ray->ori.z, 2) * pow(tan(con->coeff), 2));
	d = determinant(a, b, c);
	if (d)
	{
		
	}
	return (d);
}

double			inter_triangle(t_object *obj, t_ray *ray)
{
	t_triangle	*tri;
	t_vec		w;
	t_vec		tmp;
	double		d;
	double		a;
	double		b;
	double		t;

	tri = &obj->prim.triangle;
	normalize(&ray->dir);
	if (!(d = -dot_product(&ray->dir, &tri->normal))) // si le triangle est parallele au rayon, on return 0
		return (0);
	w.x = ray->ori.x - tri->v1.x;
	w.y = ray->ori.y - tri->v1.y;
	w.z = ray->ori.z - tri->v1.z;
	mul_vec(&tmp, &w, &tri->v3);
	a = -dot_product(&tmp, &ray->dir) / d;
	mul_vec(&tmp, &tri->v2, &w);
	b = -dot_product(&tmp, &ray->dir) / d;
	mul_vec(&tmp, &tri->v2, &tri->v3);
	t = dot_product(&tmp, &w) / d;
	if (a > 0 && b > 0 && a + b <= 1)
		return (t);
	return (0);
}
