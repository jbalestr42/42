/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:20:58 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/19 16:30:48 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

# define PERSISTANCE 0.7
# define FREQUENCY 0.2
# define OCTAVES 5

# include "ray_tracer.h"

typedef struct	s_perlin
{
	t_vertex	integer;
	t_vertex	fract;
	t_vertex	a;
	t_vertex	b;
	t_vertex	c;
	t_vertex	d;
	double		v;
	double		w;
}				t_perlin;

typedef struct	s_effect
{
	t_color		color;
	t_vertex	c1;
	t_vertex	c2;
	double		value;
	double		result;	
}				t_effect;

double			cos_interpolate(double a, double b, double t);
double			noise_3d(double x, double y, double z);
void			s_n_integer(t_perlin *p, double x, double y, double z);
double			smooth_noise(double x, double y, double z);
double			ft_perlin(double x, double y, double z);
t_color			perlin_zebra(double x, double y, double z, t_color pix);
t_color			perlin_marble(double x, double y, double z);
t_color			perlin_wood(double x, double y, double z);

#endif
