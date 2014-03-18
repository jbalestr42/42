/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:20:58 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/14 16:59:49 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

# define PERSISTANCE 0.7
# define FREQUENCY 0.04
# define OCTAVES 5

# define VAL1 0.2
# define VAL2 0.5
# define VAL3 0.7

# include "ray_tracer.h"

typedef struct	s_perlin
{
	t_vertex		integer;
	t_vertex		doubler;
	t_vertex		a;
	t_vertex		b;
	t_vertex		c;
	t_vertex		d;
	double		v;
	double		w;
}				t_perlin;

double          cos_interpolate(double a, double b, double t);
double			noise_2d(double x, double y);
double			noise_3d(double x, double y, double z);
void			s_n_integer(t_perlin *p, double x, double y, double z);
double			smooth_noise(double x, double y, double z);
double			ft_perlin(t_env *e, double x, double y, double z);
t_color			ft_more_effect(t_env *e, double x, double y, double z);
t_color			marble(t_env *e, double x, double y, double z);
t_color			wood(t_env *e, double x, double y, double z);
void			obtenirPixel(t_env *e, double x, double y, double z);
void			check_color(t_env *e);

#endif
