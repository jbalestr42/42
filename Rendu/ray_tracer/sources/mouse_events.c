/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:34:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/05 13:56:57 by jbalestr         ###   ########.fr       */
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

void			check_event_load_type(t_env *e)
{
	if (!e->progressive_load)
	{
		e->screens[OPTIONS].buttons[0].state = HOVER;
		e->progressive_load = 1;
	}
	else
	{
		e->screens[OPTIONS].buttons[0].state = NONE;
		e->progressive_load = 0;
	}
}

void			mouse_event_choose_scene(t_env *e)
{
	ft_putstr("Reading scene : ");
	ft_putstr(e->cur_button->name);
	ft_putstr("\n");
	if (e->progressive_load)
		e->cur_screen = LOAD_SCREEN;
	else
		e->cur_screen = RAY_TRACE;
	// init_scene ici avec en parametre la chaine vers la scene, il faut verifier si le fichier existe toujours, et ajotuer le nom de dossier devant scenes/
	if (e->cur_button)
	{
		init_scene(e, e->cur_button->name);
		draw_image(e);
	}
}

void			mouse_event_void(t_env *e)
{
	(void)e;
}
