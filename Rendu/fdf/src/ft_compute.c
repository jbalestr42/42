/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 14:11:36 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/17 16:23:58 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		ft_get_point(t_env *e, t_point *pt, t_point (*f)(int, int, int))
{
	t_point		new;

	new.x = (ORIGIN_X + pt->x * STEP_X * e->scale);
	new.y = (ORIGIN_Y + pt->y * STEP_Y) * e->scale;
	new.z = pt->z * e->scale;
	new = (*f)(new.x, new.y, new.z);
	return (new);
}

t_point		ft_para(int x, int y, int z)
{
	t_point		pt;

	pt.x = x + CST_1 * z;
	pt.y = y + CST_1 / 2 * z;
	pt.z = z;
	return (pt);
}

t_point		ft_iso(int x, int y, int z)
{
	t_point		pt;

	pt.x = CST_1 * x - CST_2 * y;
	pt.y = -z + CST_1 / 2 * x + CST_2 / 2 * y;
	pt.z = z;
	return (pt);
}
