/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:10:28 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/03 21:20:01 by pciavald         ###   ########.fr       */
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

#include <stdio.h>
int			mouse_hook_press(int button, int x, int y, t_env *e)
{
	printf("%d\n", button);
	if (button == 1)
	{
		e->click_pos_x = x;
		e->click_pos_y = y;
	}
	else if (button == 4)
		e->zoom += e->zoom * 0.1f;
	else if (button == 5)
		e->zoom -= e->zoom * 0.1f;
	expose_hook(e);
	return (0);
}

int			mouse_hook_move(int x, int y, t_env *e)
{
	printf("move\n");
	e->move_pos_x = x;
	e->move_pos_y = y;
	//expose_hook(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->screen.ptr, 0, 0);
	return (0);
}
