/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:55:01 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/27 12:18:30 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "ray_tracer.h"

typedef struct		s_compute
{
	t_ray			ray;
	t_mesh			*mesh;
	t_vertex		inter;
	t_ray			ray_light;
}					t_compute;

typedef struct		s_refr
{
	t_color			tmp;
	t_vector		n;
	t_vector		t;
	t_color			col;
	double			r;
	double			cos_i;
	double			cos_t2;
}					t_refr;

#endif
