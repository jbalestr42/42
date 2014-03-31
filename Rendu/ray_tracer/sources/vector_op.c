/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:39:15 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 13:13:26 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_vector		add(t_vector u, t_vector v)
{
	t_vector	new;

	new.x = u.x + v.x;
	new.y = u.y + v.y;
	new.z = u.z + v.z;
	return (new);
}

t_vector		sub(t_vector u, t_vector v)
{
	t_vector	new;

	new.x = u.x - v.x;
	new.y = u.y - v.y;
	new.z = u.z - v.z;
	return (new);
}

t_vector		prod(t_vector u, t_vector v)
{
	t_vector	new;

	new.x = u.x * v.x;
	new.y = u.y * v.y;
	new.z = u.z * v.z;
	return (new);
}

t_vector		cross(t_vector u, t_vector v)
{
	t_vector	new;

	new.x = u.y * v.z - u.z * v.y;
	new.y = u.z * v.x - u.x * v.z;
	new.z = u.x * v.y - u.y * v.x;
	return (new);
}

t_vector		prod_val(t_vector u, double val)
{
	t_vector	new;

	new.x = u.x * val;
	new.y = u.y * val;
	new.z = u.z * val;
	return (new);
}
