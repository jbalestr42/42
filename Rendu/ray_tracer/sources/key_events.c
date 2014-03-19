/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/19 12:43:41 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"

void	key_event_save(t_env *e)
{
	ft_putstr("Saving image to save.ppm ...\n");
	if (e->cur_screen == RAY_TRACE)
		save_ppm(e);
	ft_putstr("Done !\n");
}

void	key_event_esc(t_env *e)
{
	if (e->cur_screen == MENU)
		ft_error(1, e, "Deleting objects...");
	else if (e->cur_screen == RAY_TRACE || e->cur_screen == OPTIONS)
		e->cur_screen = MENU;
	else if (e->cur_screen == CHOOSE)
		e->cur_screen = MENU;
	expose_hook(e);
}
