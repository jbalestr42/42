/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:10:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/05 14:49:45 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"
#include <mlx.h>

int				key_hook_press(int keycode, t_env *e)
{
	int		i;

	i = 0;
	while (i < NB_KEY_EVENT)
	{
		if (e->key_events[i].keycode == keycode)
		{
			if (e->key_events[i].is_press == 0)
			{
				e->key_events[i].is_press = 1;
				e->key_events[i].event(e);
			}
			break ;
		}
		i++;
	}
	return (0);
}

int				key_hook_release(int keycode, t_env *e)
{
	int		i;

	i = 0;
	while (i < NB_KEY_EVENT)
	{
		if (e->key_events[i].keycode == keycode)
		{
			if (e->key_events[i].is_press == 1)
				e->key_events[i].is_press = 0;
			break ;
		}
		i++;
	}
	return (0);
}

int				mouse_hook_press(int button, int x, int y, t_env *e)
{
	t_screen	*s;
	int			i;

	if (button != 1)
		return (0);
	i = -1;
	s = &e->screens[e->cur_screen];
	while (++i < s->nb_button)
	{
		if (s->buttons[i].x_pos < x && x <= s->buttons[i].x_pos + s->buttons[i].img.width)
		{
			if (s->buttons[i].y_pos < y && y <= s->buttons[i].y_pos + s->buttons[i].img.height / 2)
			{
				e->cur_button = &s->buttons[i];
				s->buttons[i].event(e);
			}
		}
	}
	expose_hook(e);
	return (0);
}

int				mouse_hook_move(int x, int y, t_env *e)
{
	t_screen	*s;
	int			i;

	i = -1;
	s = &e->screens[e->cur_screen];
	while (++i < s->nb_button)
	{
		if (!s->buttons[i].check_box)
		{
			if (s->buttons[i].x_pos < x && x <= s->buttons[i].x_pos + s->buttons[i].img.width)
			{
				if (s->buttons[i].y_pos < y && y <= s->buttons[i].y_pos + s->buttons[i].img.height / 2)
					s->buttons[i].state = HOVER;
				else
					s->buttons[i].state = NONE;
			}
			else
				s->buttons[i].state = NONE;
		}
	}
	expose_hook(e);
	return (0);
}

int				expose_hook(t_env *e)
{
	t_screen	*s;
	t_img		img;
	int			k;
	int			x;
	int			y;

	k = -1;
	s = &e->screens[e->cur_screen];
	img = s->background;
	while (++k < s->nb_button)
	{
		x = -1;
		while (++x < s->buttons[k].img.width)
		{
			y = -1;
			while (++y < s->buttons[k].frame_size)
			{
				int t = (s->buttons[k].state * s->buttons[k].frame_size + y) * s->buttons[k].img.size_line + (x * s->buttons[k].img.bpp);
				if (t > 0 && t < s->buttons[k].img.max_size)
				{
					int tt = (s->buttons[k].y_pos + y) * img.size_line
							+ ((s->buttons[k].x_pos + x) * img.bpp);
					
					if (tt > 0 && tt < img.max_size)
					{
						img.img[tt] = s->buttons[k].img.img[t];
						img.img[tt + 1] = s->buttons[k].img.img[t + 1];
						img.img[tt + 2] = s->buttons[k].img.img[t + 2];
					}
				}
			}
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, img.ptr, 0, 0);
	if (e->cur_screen == CHOOSE)
	{
		k = e->screens[CHOOSE].nb_button;
		while (--k >= 0)
		{
			if (e->screens[CHOOSE].buttons[k].name)
				mlx_string_put(e->mlx, e->win,
					e->screens[CHOOSE].buttons[k].x_pos + 10,
					e->screens[CHOOSE].buttons[k].y_pos + 10, 0xffffff,
					e->screens[CHOOSE].buttons[k].name);
		}
	}
	return (0);
}
