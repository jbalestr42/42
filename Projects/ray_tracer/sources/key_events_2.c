/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:37:55 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/27 19:09:03 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"
#include "perlin.h"

void	key_event_b_and_w(t_env *e)
{
	if (e->cur_screen == RAY_TRACE)
	{
		post_processing(e, B_AND_W);
		expose_hook(e);
	}
}

void	key_event_sepia(t_env *e)
{
	if (e->cur_screen == RAY_TRACE)
	{
		post_processing(e, SEPIA);
		expose_hook(e);
	}
}

void	key_event_negative(t_env *e)
{
	if (e->cur_screen == RAY_TRACE)
	{
		post_processing(e, NEGATIVE);
		expose_hook(e);
	}
}

void	key_event_none(t_env *e)
{
	int	x;

	if (e->cur_screen == RAY_TRACE)
	{
		x = -1;
		while (++x < e->img_tmp.max_size)
			e->screens[RAY_TRACE].background.img[x] = e->img_tmp.img[x];
		expose_hook(e);
	}
}
