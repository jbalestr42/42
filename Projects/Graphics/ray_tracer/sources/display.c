/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:10:03 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:10:04 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ray_tracer.h"
#include "menu.h"

void			display_background(t_button *b, t_img *i)
{
	int			t;
	int			tt;
	int			x;
	int			y;

	x = -1;
	while (++x < b->img.width)
	{
		y = -1;
		while (++y < b->frame_size)
		{
			t = (b->state * b->frame_size + y) * b->img.size_line
					+ (x * b->img.bpp);
			if (t > 0 && t < b->img.max_size)
			{
				tt = (b->y_pos + y) * i->size_line + ((b->x_pos + x) * i->bpp);
				if (tt > 0 && tt < i->max_size)
				{
					i->img[tt] = b->img.img[t];
					i->img[tt + 1] = b->img.img[t + 1];
					i->img[tt + 2] = b->img.img[t + 2];
				}
			}
		}
	}
}

void			display_choose(t_env *e)
{
	int			k;

	if (e->cur_screen >= MENU && e->cur_screen < MENU + e->nb_panel)
	{
		k = e->screens[e->cur_screen].nb_button;
		while (--k >= 0)
		{
			if (e->screens[e->cur_screen].buttons[k].name)
				mlx_string_put(e->mlx, e->win,
					e->screens[e->cur_screen].buttons[k].x_pos + 10,
					e->screens[e->cur_screen].buttons[k].y_pos + 10, 0xffffff,
					e->screens[e->cur_screen].buttons[k].name);
		}
	}
}
