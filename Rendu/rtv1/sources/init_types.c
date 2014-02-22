/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 11:59:10 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 11:59:14 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void		init_types(t_env *e)
{
	e->get_inter[T_SPHERE] = inter_sphere;
	e->get_inter[T_PLAN] = inter_plan;
	e->get_inter[T_CYLINDER] = inter_cylinder;
	e->get_inter[T_CONE] = inter_cone;
}
