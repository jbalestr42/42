/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_vec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 12:01:52 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 12:03:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void		add_vec(t_vec *res, t_vec *a, t_vec *b)
{
	if (!res || !a || !b)
		return ;
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
}

void		sub_vec(t_vec *res, t_vec *a, t_vec *b)
{
	if (!res || !a || !b)
		return ;
	res->x = a->x - b->x;
	res->y = a->y - b->y;
	res->z = a->z - b->z;
}

void		mul_vec(t_vec *res, t_vec *a, t_vec *b)
{
	t_vec	tmp;

	if (!res || !a || !b)
		return ;
	tmp.x = a->x;
	tmp.y = a->y;
	tmp.z = a->z;
	res->x = tmp.y * b->z - tmp.z * b->y;
	res->y = tmp.z * b->x - tmp.x * b->z;
	res->z = tmp.x * b->y - tmp.y * b->x;
}

void		mul_vec_val(t_vec *res, t_vec *p, double val)
{
	if (!res || !p)
		return ;
	res->x = p->x * val;
	res->y = p->y * val;
	res->z = p->z * val;
}
