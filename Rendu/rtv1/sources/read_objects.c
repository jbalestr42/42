/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 10:44:38 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 12:13:37 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_light			read_light(t_env *e, char *s)
{
	t_light		light;
	char		**tmp;

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 4)
	{
		light.color = read_color(e, tmp[0]);
		light.pos.x = ft_atoi(tmp[1]);
		light.pos.y = ft_atoi(tmp[2]);
		light.pos.z = ft_atoi(tmp[3]);
		free_split(tmp);
	}
	else
		ft_error(1, e, "Light wrong format : ignore light.\n");
	return (light);
}

t_object		read_cylinder(t_env *e, char *s)
{
	t_object	obj;
	char		**tmp;

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 8)
	{
		obj.type = T_CYLINDER;
		obj.color = read_color(e, tmp[0]);
		obj.light.r = obj.color.r;
		obj.light.g = obj.color.g;
		obj.light.b = obj.color.b;
		obj.prim.cylinder.pos.x = ft_atoi(tmp[1]);
		obj.prim.cylinder.pos.y = ft_atoi(tmp[2]);
		obj.prim.cylinder.pos.z = ft_atoi(tmp[3]);
		obj.prim.cylinder.dir.x = ft_atoi(tmp[4]);
		obj.prim.cylinder.dir.y = ft_atoi(tmp[5]);
		obj.prim.cylinder.dir.z = ft_atoi(tmp[6]);
		obj.prim.cylinder.radius = ft_atoi(tmp[7]);
		free_split(tmp);
	}
	else
		ft_error(1, e, "Cylinder wrong format : ignore cylinder.\n");
	return (obj);
}

t_object		read_cone(t_env *e, char *s)
{
	t_object	obj;
	char		**tmp;

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 8)
	{
		obj.type = T_CONE;
		obj.color = read_color(e, tmp[0]);
		obj.light.r = obj.color.r;
		obj.light.g = obj.color.g;
		obj.light.b = obj.color.b;
		obj.prim.cone.pos.x = ft_atoi(tmp[1]);
		obj.prim.cone.pos.y = ft_atoi(tmp[2]);
		obj.prim.cone.pos.z = ft_atoi(tmp[3]);
		obj.prim.cone.dir.x = ft_atoi(tmp[4]);
		obj.prim.cone.dir.y = ft_atoi(tmp[5]);
		obj.prim.cone.dir.z = ft_atoi(tmp[6]);
		obj.prim.cone.coeff = ft_atoi(tmp[7]);
		free_split(tmp);
	}
	else
		ft_error(1, e, "Cone wrong format : ignore cone.\n");
	return (obj);
}

t_object		read_sphere(t_env *e, char *s)
{
	t_object	obj;
	char		**tmp;

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 5)
	{
		obj.type = T_SPHERE;
		obj.color = read_color(e, tmp[0]);
		obj.prim.sphere.center.x = ft_atoi(tmp[1]);
		obj.prim.sphere.center.y = ft_atoi(tmp[2]);
		obj.prim.sphere.center.z = ft_atoi(tmp[3]);
		obj.prim.sphere.radius = ft_atoi(tmp[4]);
		free_split(tmp);
	}
	else
		ft_error(1, e, "Sphere wrong format : ignore sphere.\n");
	return (obj);
}

t_object		read_plan(t_env *e, char *s)
{
	t_object	obj;
	char		**tmp;

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 7)
	{
		obj.type = T_PLAN;
		obj.color = read_color(e, tmp[0]);
		obj.light.r = obj.color.r;
		obj.light.g = obj.color.g;
		obj.light.b = obj.color.b;
		obj.prim.plan.pos.x = ft_atoi(tmp[1]);
		obj.prim.plan.pos.y = ft_atoi(tmp[2]);
		obj.prim.plan.pos.z = ft_atoi(tmp[3]);
		obj.prim.plan.normal.x = ft_atoi(tmp[4]);
		obj.prim.plan.normal.y = ft_atoi(tmp[5]);
		obj.prim.plan.normal.z = ft_atoi(tmp[6]);
		normalize(&obj.prim.plan.normal);
		free_split(tmp);
	}
	else
		ft_error(1, e, "Plan wrong format : ignore plan.\n");
	return (obj);
}

t_object		read_triangle(t_env *e, char *s)
{
	t_object	obj;
	char		**tmp;

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 10)
	{
		obj.type = T_TRIANGLE;
		obj.color = read_color(e, tmp[0]);
		obj.light.r = obj.color.r;
		obj.light.g = obj.color.g;
		obj.light.b = obj.color.b;
		obj.prim.triangle.v1.x = ft_atoi(tmp[1]);
		obj.prim.triangle.v1.y = ft_atoi(tmp[2]);
		obj.prim.triangle.v1.z = ft_atoi(tmp[3]);
		obj.prim.triangle.v2.x = ft_atoi(tmp[4]);
		obj.prim.triangle.v2.y = ft_atoi(tmp[5]);
		obj.prim.triangle.v2.z = ft_atoi(tmp[6]);
		obj.prim.triangle.v3.x = ft_atoi(tmp[7]);
		obj.prim.triangle.v3.y = ft_atoi(tmp[8]);
		obj.prim.triangle.v3.z = ft_atoi(tmp[9]);
		free_split(tmp);
	}
	else
		ft_error(1, e, "Triangle wrong format : ignore triangle.\n");
	return (obj);
}
