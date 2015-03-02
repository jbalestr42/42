/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 14:24:41 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 18:41:02 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	event_disco(t_env *e)
{
	e->fov = 179;
	e->dist_plan_player = (WIDTH / 2) / ft_tan(e->fov / 2);
	e->step_angle = (float)e->fov / WIDTH;
}

void	event_normal(t_env *e)
{
	e->fov = 60;
	e->dist_plan_player = (WIDTH / 2) / ft_tan(e->fov / 2);
	e->step_angle = (float)e->fov / WIDTH;
}
