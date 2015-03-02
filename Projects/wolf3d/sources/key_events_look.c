/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_look.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 18:34:19 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_event_down(t_env *e)
{
	e->current_height -= SPEED_ROT;
}

void	key_event_up(t_env *e)
{
	e->current_height += SPEED_ROT;
}

void	key_event_left(t_env *e)
{
	e->pov.alpha += SPEED_ROT;
	if (e->pov.alpha > 360)
		e->pov.alpha -= 360;
}

void	key_event_right(t_env *e)
{
	e->pov.alpha -= SPEED_ROT;
	if (e->pov.alpha < 0)
		e->pov.alpha += 360;
}
