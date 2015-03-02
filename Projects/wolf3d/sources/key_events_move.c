/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 20:34:20 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 22:27:28 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_event_key_s(t_env *e)
{
	t_point		newpos;

	newpos.x = e->pov.pos.x - SPEED * ft_cos(e->pov.alpha);
	newpos.y = e->pov.pos.y + SPEED * ft_sin(e->pov.alpha);
	compute_pos(e, &newpos);
}

void	key_event_key_w(t_env *e)
{
	t_point		newpos;

	newpos.x = e->pov.pos.x + SPEED * ft_cos(e->pov.alpha);
	newpos.y = e->pov.pos.y - SPEED * ft_sin(e->pov.alpha);
	compute_pos(e, &newpos);
}

void	key_event_key_a(t_env *e)
{
	t_point		newpos;

	newpos.x = e->pov.pos.x + SPEED * ft_cos(e->pov.alpha + 90);
	newpos.y = e->pov.pos.y - SPEED * ft_sin(e->pov.alpha + 90);
	compute_pos(e, &newpos);
}

void	key_event_key_d(t_env *e)
{
	t_point		newpos;

	newpos.x = e->pov.pos.x + SPEED * ft_cos(e->pov.alpha - 90);
	newpos.y = e->pov.pos.y - SPEED * ft_sin(e->pov.alpha - 90);
	compute_pos(e, &newpos);
}
