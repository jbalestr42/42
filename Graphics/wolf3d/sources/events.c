/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:10:28 by jbalestr          #+#    #+#             */
/*   Updated: 2015/07/09 15:19:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <mlx.h>
#include <time.h>
#include <stdio.h>

int				key_hook_press(int keycode, t_env *e)
{
	int		i;

	printf("%d\n",keycode);
	i = 0;
	while (i < NB_KEY_EVENT)
	{
		if (e->key_events[i].keycode == keycode)
		{
			if (e->key_events[i].is_press == 0)
				e->key_events[i].is_press = 1;
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

int				expose_hook(t_env *e)
{
	ft_draw_view(e);
	mlx_put_image_to_window(e->mlx, e->win, e->screen.ptr, 0, 0);
	return (0);
}

static void		update(t_env *e)
{
	int		i;

	i = 0;
	while (i < NB_WALL)
	{
		e->walls[i].current_frame += e->framerate * e->walls[i].speed;
		if (e->walls[i].current_frame > e->walls[i].frames)
			e->walls[i].current_frame = 0;
		i++;
	}
	i = 0;
	while (i < NB_KEY_EVENT)
	{
		if (e->key_events[i].is_press)
			e->key_events[i].event(e);
		i++;
	}
	if (e->trig_event)
		e->trig_event(e);
	expose_hook(e);
}

int				loop_hook(t_env *e)
{
	float	time;

	time = clock();
	e->framerate = (time - e->last_time) / 100000;
	e->last_time = time;
	if (e->splash.current_frame < 2)
	{
		mlx_put_image_to_window(e->mlx, e->win, e->splash.ptr, 0, 0);
		e->splash.current_frame += e->framerate;
	}
	else
		update(e);
	return (0);
}
