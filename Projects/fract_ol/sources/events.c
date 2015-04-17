/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:10:28 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/27 20:28:35 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdio.h>

int			key_hook_press(int keycode, t_env *e)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		ft_envdel(e);
	else if (keycode == 65361)
		e->offset_x -= 0.1f / e->zoom;
	else if (keycode == 65363)
		e->offset_x += 0.1f / e->zoom;
	else if (keycode == 65362)
		e->offset_y -= 0.1f / e->zoom;
	else if (keycode == 65364)
		e->offset_y += 0.1f / e->zoom;
	else if (keycode == 114)
		init_var(e);
	else if (keycode == 65289)
		e->current_fractal = (e->current_fractal + 1) % NB_FRACTAL;
	key_press_color_fractal(keycode, e);
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
	update_zoom(e);
	expose_hook(e);
	return (0);
}

int			mouse_hook_move(int x, int y, t_env *e)
{
	e->move_pos_x = x;
	e->move_pos_y = y;
	e->mouse_x = x / (double)WIDTH;
	e->mouse_y = y / (double)HEIGHT;
	e->julia_cx = -0.8 + e->mouse_x * 1.1;
	e->julia_cy = 0.3 - e->mouse_y * 0.32;
	if (x % 5 == 0 || y % 5 == 0)
		expose_hook(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->screen.ptr, 0, 0);
	return (0);
}
