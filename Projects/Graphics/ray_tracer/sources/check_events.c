/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:09:04 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:09:05 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void			check_event_ocean(t_env *e)
{
	if (!e->ocean)
	{
		e->screens[OPTIONS].buttons[0].state = HOVER;
		e->ocean = 1;
	}
	else
	{
		e->screens[OPTIONS].buttons[0].state = NONE;
		e->ocean = 0;
	}
}

void			check_event_aa(t_env *e)
{
	if (!e->aa_active)
	{
		e->screens[OPTIONS].buttons[1].state = HOVER;
		e->aa_active = 1;
	}
	else
	{
		e->screens[OPTIONS].buttons[1].state = NONE;
		e->aa_active = 0;
	}
}

void			check_event_cell_shading(t_env *e)
{
	if (!e->cell_shading)
	{
		e->screens[OPTIONS].buttons[2].state = HOVER;
		e->cell_shading = 1;
	}
	else
	{
		e->screens[OPTIONS].buttons[2].state = NONE;
		e->cell_shading = 0;
	}
}

void			check_event_attenuate(t_env *e)
{
	if (!e->attenuate)
	{
		e->screens[OPTIONS].buttons[3].state = HOVER;
		e->attenuate = 1;
	}
	else
	{
		e->screens[OPTIONS].buttons[3].state = NONE;
		e->attenuate = 0;
	}
}

void			check_event_video(t_env *e)
{
	if (!e->video)
	{
		e->screens[OPTIONS].buttons[4].state = HOVER;
		e->video = 1;
	}
	else
	{
		e->screens[OPTIONS].buttons[4].state = NONE;
		e->video = 0;
	}
}
