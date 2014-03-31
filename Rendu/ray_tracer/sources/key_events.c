/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/26 15:56:35 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

void	key_event_save(t_env *e)
{
	if (e->cur_screen == RAY_TRACE)
	{
		ft_putstr("Saving image to save.ppm ...\n");
		save_ppm(e);
		ft_putstr("Done !\n");
	}
}

void	key_event_run_video(t_env *e)
{
	if (e->video && e->cur_screen == RAY_TRACE)
		display_video(e, e->vid);
}

void	key_event_esc(t_env *e)
{
	if (e->cur_screen >= MENU && e->cur_screen < MENU + e->nb_panel)
		ft_error(1, e, "Deleting objects...");
	else if (e->cur_screen == RAY_TRACE)
	{
		escape_screen(e);
		e->cur_screen = MENU;
	}
	else if (e->cur_screen == OPTIONS)
		e->cur_screen = MENU;
	else if (e->cur_screen == CHOOSE)
		e->cur_screen = MENU;
	expose_hook(e);
}
