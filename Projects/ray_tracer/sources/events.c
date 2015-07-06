/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:10:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/26 14:06:28 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ray_tracer.h"

int				key_hook_press(int keycode, t_env *e)
{
	int			i;

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
	int			i;

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
		if (s->buttons[i].x_pos < x && x <= s->buttons[i].x_pos
						+ s->buttons[i].img.width)
		{
			if (s->buttons[i].y_pos < y && y <= s->buttons[i].y_pos
							+ s->buttons[i].img.height / 2)
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
			if (s->buttons[i].x_pos < x && x <= s->buttons[i].x_pos +
							s->buttons[i].img.width)
			{
				if (s->buttons[i].y_pos < y && y <= s->buttons[i].y_pos
								+ s->buttons[i].img.height / 2)
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

	k = -1;
	s = &e->screens[e->cur_screen];
	img = s->background;
	while (++k < s->nb_button)
		display_background(&s->buttons[k], &img);
	mlx_put_image_to_window(e->mlx, e->win, img.ptr, 0, 0);
	display_choose(e);
	return (0);
}
