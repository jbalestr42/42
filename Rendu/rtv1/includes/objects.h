/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:49:36 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:50:07 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

/*
** ori : position
** dir : direction (unit vector)
*/
typedef struct		s_ray
{
	t_vec			ori;
	t_vec			dir;
	double			dist;
}					t_ray;

typedef struct		s_cam
{
	t_vec			ori;
	t_vec			dir;
	t_vec			right;
	t_vec			down;
}					t_cam;

typedef struct		s_light
{
	t_vec			pos;
	t_color			color;
}					t_light;

typedef struct		s_cylinder
{
	t_vec			pos;
	t_vec			dir;
	double			radius;
}					t_cylinder;

typedef struct		s_cone
{
	t_vec			pos;
	t_vec			dir;
	double			coeff;
}					t_cone;

typedef struct		s_sphere
{
	t_vec			center;
	double			radius;
}					t_sphere;

typedef struct		s_plan
{
	t_vec			pos;
	t_vec			normal;
}					t_plan;

typedef struct		s_triangle
{
	t_vec			v1;
	t_vec			v2;
	t_vec			v3;
	t_vec			normal;
}					t_triangle;

typedef enum		e_type
{
	T_SPHERE, T_PLAN, T_CYLINDER, T_CONE, T_TRIANGLE
}					t_type;

typedef union		u_prim
{
	t_sphere		sphere;
	t_plan			plan;
	t_cylinder		cylinder;
	t_cone			cone;
	t_triangle		triangle;
}					t_prim;

typedef struct		s_object
{
	t_prim			prim;
	t_color			color;
	t_color			light;
	int				type;
}					t_object;

#endif /* !OBJECTS_H */
