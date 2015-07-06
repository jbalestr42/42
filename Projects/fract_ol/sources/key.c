/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 18:05:21 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/27 20:28:35 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		update_zoom(t_env *e)
{
	double c0x;
	double c0y;

	c0x = (e->c0x + e->offset_x) / e->zoom;
	c0y = (e->c0y + e->offset_y) / e->zoom;
	e->offset_zoom_x += c0x - e->mouse_x * c0x * 2.0;
	e->offset_zoom_y += c0y - e->mouse_y * c0y * 2.0;
	e->zoom_width = e->zoom * (double)HALF_WIDTH;
	e->zoom_height = e->zoom * (double)HALF_HEIGHT;
}

void		key_press_color_fractal(int keycode, t_env *e)
{
	if (keycode == 65505)
	{
		e->current_fractal--;
		if (e->current_fractal < 0)
			e->current_fractal = NB_FRACTAL - 1;
	}
	else if (keycode == 65451)
	{
		e->zoom += e->zoom * 0.1f;
		update_zoom(e);
	}
	else if (keycode == 65453)
	{
		e->zoom -= e->zoom * 0.1f;
		update_zoom(e);
	}
	else if (keycode == 38)
		e->current_pal = (e->current_pal + 1) % NB_PAL;
	else if (keycode == 233)
	{
		e->current_pal--;
		if (e->current_pal < 0)
			e->current_pal = NB_PAL - 1;
	}
}
