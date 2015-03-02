/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:34:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 17:15:13 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"
#include "video.h"

void			mouse_event_choose_scene(t_env *e)
{
	if (!e->cur_button->name)
	{
		ft_putstr("This button is empty !\n");
		return ;
	}
	ft_putstr("Reading scene : ");
	ft_putstr(e->cur_button->name);
	ft_putstr("\n");
	if (e->cur_button)
	{
		if (init_scene(e, e->cur_button->name) == -1)
			return ;
		if (e->video)
			create_pics(e);
		else
			draw_image(e);
	}
}

void			mouse_event_yolo(t_env *e)
{
	(void)e;
	ft_putstr("You push the YOLO button :D\n");
	ft_putstr("... you failed to push the button :/\n");
}

void			mouse_event_ls(t_env *e)
{
	if (e->cur_screen == MENU)
		e->cur_screen = MENU + (e->nb_panel - 1);
	else
		e->cur_screen -= 1;
	e->cur_panel = e->cur_screen - MENU;
}

void			mouse_event_rs(t_env *e)
{
	if (e->cur_screen == MENU + (e->nb_panel - 1))
		e->cur_screen = MENU;
	else
		e->cur_screen += 1;
	e->cur_panel = e->cur_screen - MENU;
}
