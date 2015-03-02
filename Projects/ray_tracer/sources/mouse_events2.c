/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:34:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 05:15:48 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void			mouse_event_leave(t_env *e)
{
	ft_error(1, e, "Deleting objects...");
}

void			mouse_event_ray_trace(t_env *e)
{
	e->cur_screen = CHOOSE;
}

void			mouse_event_options(t_env *e)
{
	e->cur_screen = OPTIONS;
}

void			mouse_event_void(t_env *e)
{
	(void)e;
}

void			check_event_back(t_env *e)
{
	e->cur_screen = MENU;
}
