/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 12:15:02 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/02 16:29:35 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == ESC)
		exit(0);
	if (keycode == UP)
		e->cam.y -= 5;
	if (keycode == DOWN)
		e->cam.y += 5;
	if (keycode == LEFT)
		e->cam.x -= 5;
	if (keycode == RIGHT)
		e->cam.x += 5;
	if (keycode == PLUS)
		e->scale += 0.1;
	if (keycode == MINUS)
		e->scale -= 0.1;
	expose_hook(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_draw_map(e);
	return (0);
}

int		mouse_hook(int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)e;
	return (0);
}
