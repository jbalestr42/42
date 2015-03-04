/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:10:28 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/04 18:42:33 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

int			key_hook_press(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	if (keycode == ESC)
		exit(0);
	else if (keycode == LEFT)
		e->offset_x -= 0.1f / e->zoom;
	else if (keycode == RIGHT)
		e->offset_x += 0.1f / e->zoom;
	else if (keycode == UP)
		e->offset_y -= 0.1f / e->zoom;
	else if (keycode == DOWN)
		e->offset_y += 0.1f / e->zoom;
	expose_hook(e);
	return (0);
}

int			mouse_hook_press(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->click_pos_x = x;
		e->click_pos_y = y;
	}
	else if (button == 5)
		e->zoom += e->zoom * 0.1f;
	else if (button == 4)
		e->zoom -= e->zoom * 0.1f;
	double c0x = 1.5 * (-HALF_WIDTH) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double c0y = (-HALF_HEIGHT) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
	e->offset_zoom_x += c0x - e->mouse_x * c0x * 2.0;
	e->offset_zoom_y += c0y - e->mouse_y * c0y * 2.0;
	expose_hook(e);
	return (0);
}

int			mouse_hook_move(int x, int y, t_env *e)
{
	e->move_pos_x = x;
	e->move_pos_y = y;
	e->mouse_x = x / (double)WIDTH;
	e->mouse_y = y / (double)HEIGHT;
	expose_hook(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->screen.ptr, 0, 0);
	return (0);
}
