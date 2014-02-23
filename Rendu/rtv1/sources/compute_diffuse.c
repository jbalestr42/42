/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_diffuse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 12:20:31 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:21:33 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

static void		diff_col(t_color *c, t_color *objc, t_color *lic, double diff)
{
	c->r = 256 * (diff * ((double)lic->r / 256) * ((double)objc->r / 256));
	c->g = 256 * (diff * ((double)lic->g / 256) * ((double)objc->g / 256));
	c->b = 256 * (diff * ((double)lic->b / 256) * ((double)objc->b / 256));
}

t_color			diffuse_sphere(t_light *li, t_object *obj, t_vec *vi, double sh)
{
	t_color		col;
	t_vec		normal;
	t_vec		u;
	double		dot;
	double		diff;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	sub_vec(&u, &li->pos, vi);
	normalize(&u);
	normal = normal_sphere(&obj->prim.sphere, vi);
	dot = dot_product(&u, &normal);
	if (dot > 0)
	{
		diff = dot * 0.1 * sh;
		diff_col(&col, &obj->color, &li->color, diff);
	}
	return (col);
}

t_color			diffuse_cyl(t_light *li, t_object *obj, t_vec *vi, double sh)
{
	t_color		col;
	t_vec		normal;
	t_vec		u;
	double		dot;
	double		diff;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	sub_vec(&u, &li->pos, vi);
	normalize(&u);
	normal = normal_cylinder(&obj->prim.cylinder, vi);
	dot = dot_product(&u, &normal);
	if (dot > 0)
	{
		diff = dot * 0.2 * sh;
		diff_col(&col, &obj->color, &li->color, diff);
	}
	return (col);
}

t_color			diffuse_triangle(t_light *li, t_object *obj, t_vec *vi, double sh)
{
	t_color		col;
	t_vec		u;
	double		dot;
	double		diff;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	sub_vec(&u, &li->pos, vi);
	normalize(&u);
	dot = dot_product(&u, &obj->prim.triangle.normal);
	if (dot > 0)
	{
		diff = dot * 0.9 * sh;
		diff_col(&col, &obj->color, &li->color, diff);
	}
	return (col);
}

t_color			diffuse_plan(t_light *li, t_object *obj, t_vec *vi, double sh)
{
	t_color		col;
	t_vec		u;
	double		dot;
	double		diff;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	sub_vec(&u, &li->pos, vi);
	normalize(&u);
	dot = dot_product(&u, &obj->prim.plan.normal);
	if (dot > 0)
	{
		diff = dot * 0.9 * sh;
		diff_col(&col, &obj->color, &li->color, diff);
	}
	return (col);
}

t_color			compute_diff(t_light *li, t_object *obj, t_vec *vi, double sh)
{
	t_color		col;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	if (obj->type == T_SPHERE)
		col = diffuse_sphere(li, obj, vi, sh);
	else if (obj->type == T_PLAN)
		col = diffuse_plan(li, obj, vi, sh);
	else if (obj->type == T_TRIANGLE)
		col = diffuse_triangle(li, obj, vi, sh);
	else if (obj->type == T_CYLINDER || obj->type == T_CONE)
		col = diffuse_cyl(li, obj, vi, sh);
	return (col);
}
