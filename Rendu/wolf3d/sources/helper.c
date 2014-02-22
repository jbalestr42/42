/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 14:27:08 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 22:29:54 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	compute_pos(t_env *e, t_point *newpos)
{
	if (newpos->x >= 0 && newpos->x < e->width_px)
	{
		if (e->map[e->pov.pos.y / SIZE][newpos->x / SIZE] < WALL)
			e->pov.pos.x = newpos->x;
	}
	if (newpos->y >= 0 && newpos->y < e->height_px)
	{
		if (e->map[newpos->y / SIZE][e->pov.pos.x / SIZE] < WALL)
			e->pov.pos.y = newpos->y;
	}
	if (e->map[e->pov.pos.y / SIZE][e->pov.pos.x / SIZE] == TRIGGER)
		e->trig_event = &event_disco;
	else
		e->trig_event = &event_normal;
}

void	init_sprite_hud(t_img *img, int nb_frame, int size)
{
	img->frames = nb_frame;
	img->current_frame = 0;
	img->speed = 1;
	img->type = 0;
	img->frame_size = size;
}
